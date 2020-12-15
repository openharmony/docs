# NET<a name="ZH-CN_TOPIC_0000001055547972"></a>

-   [Overview](#section1787027955165622)
-   [Summary](#section1322897020165622)
-   [Files](#files)
-   [Data Structures](#nested-classes)
-   [Macros](#define-members)
-   [Typedefs](#typedef-members)
-   [Functions](#func-members)
-   [Details](#section2074466484165622)
-   [Function](#section1845007127165622)
-   [accept\(\)](#ga0807af5ac9dfc2a63624e8c3e0ae95ef)
-   [bind\(\)](#ga82199bcd81894331533a25f08e172480)
-   [connect\(\)](#gacdfd99b6c59c833776412fbb0c539efb)
-   [dn\_comp\(\)](#ga0438570faf515401bffa1a0d9c94a266)
-   [dn\_expand\(\)](#ga91eb2055a64b28e4942a3a760d747243)
-   [ether\_aton\(\)](#gaab4c5b65c36fc0ea96a017daabc3770a)
-   [ether\_aton\_r\(\)](#gac0954821754bace30f674e61bb9f4e5f)
-   [ether\_ntoa\(\)](#ga07e34e6ee9e272c4799780915d11677c)
-   [ether\_ntoa\_r\(\)](#ga245e21de8e82756712a5182c2674c2ad)
-   [freeifaddrs\(\)](#gabfdd6ca5469fe73ed88ba94bf8db57cc)
-   [getpeername\(\)](#ga13d77555ad4ed62dfef0ce32dd16755c)
-   [getprotobyname\(\)](#ga83ac8a97dd9d895cda658af3aa46fd55)
-   [getprotobynumber\(\)](#gac01697dc4a5b8e434522220913bd46ea)
-   [getprotoent\(\)](#gaca0da70657afbc3e723990bb229deec3)
-   [getsockname\(\)](#ga62577da7dba23abb9c99cf5c2800ab24)
-   [getsockopt\(\)](#gacfcf672e255123afb75ed4d326257073)
-   [herror\(\)](#gaa68de2578d4e0849f82d70b2f5b9af70)
-   [hstrerror\(\)](#gac1752c48d9cf2ff87e29f29df6caa585)
-   [htonl\(\)](#gac7eed08cd3b67f42bf56063157c8fd55)
-   [htons\(\)](#gaabce0f8d453c3380e5b8a3d4947eb48c)
-   [if\_freenameindex\(\)](#ga7fe55c04ac2116fa501338fdcb279cc9)
-   [inet\_addr\(\)](#ga617651ec952a1f4c9cbddbf78f4b2e2e)
-   [inet\_aton\(\)](#ga26ee8e8e3949699a9c0e02ece272d370)
-   [inet\_lnaof\(\)](#ga1facb1380b7657ca9c72fb2633b60e3b)
-   [inet\_makeaddr\(\)](#gab28732d1d740597f53fb65a09d97800c)
-   [inet\_netof\(\)](#ga3a96aa4e6abe8e6959ea63fe338174dd)
-   [inet\_network\(\)](#ga6f478437c4810fce89cf0e77d94181f8)
-   [inet\_ntoa\(\)](#ga08b9fff487151e004d9862cbf34a51ad)
-   [inet\_ntop\(\)](#gae9a2182ca3255f16723adeea14665b55)
-   [inet\_pton\(\)](#ga3f6e2b2dae98a409d77c6e3b0cebc04b)
-   [listen\(\)](#ga5989c21d05cb17caba26cef496a7beea)
-   [ntohl\(\)](#gae68530d41f32dfef707f20b2bbaa5a44)
-   [ntohs\(\)](#gaf8c87af507c59bd8fef112e5e35fe537)
-   [recv\(\)](#ga5d049263cd0e3206b93530e68dfd7403)
-   [recvfrom\(\)](#ga3089d3ee59e26bd4def3ef870175540e)
-   [recvmsg\(\)](#gaaba92f19a31c01b93e3391671a8b3dd5)
-   [send\(\)](#ga4053f5c8e26fd490ef54e2a0abf5c89f)
-   [sendmsg\(\)](#ga70c97d3a1eab72cba4461d66a1778570)
-   [sendto\(\)](#ga2587b27d2c6014c6b568a974655f41c5)
-   [setprotoent\(\)](#ga6a806414e4ae5bffb09e3a1d25d8db75)
-   [setsockopt\(\)](#ga81983de50d79d797b2ac0f0d0f28953f)
-   [shutdown\(\)](#ga402425b8e1ceab40ac38a949babcf1aa)
-   [socket\(\)](#gaf4e0711877c45a41168ac677b0670ccd)

## **Overview**<a name="section1787027955165622"></a>

**Description:**

Provides functions and data structures related to network operations. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1322897020165622"></a>

## Files<a name="files"></a>

<a name="table979041365165622"></a>
<table><thead align="left"><tr id="row396551958165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p594111837165622"><a name="p594111837165622"></a><a name="p594111837165622"></a>File Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p226808010165622"><a name="p226808010165622"></a><a name="p226808010165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row869082433165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p128530315165622"><a name="p128530315165622"></a><a name="p128530315165622"></a><a href="inet-h.md">inet.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1273581824165622"><a name="p1273581824165622"></a><a name="p1273581824165622"></a>Provides functions and data structures related to network operations. </p>
</td>
</tr>
<tr id="row2144416439165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1791836928165622"><a name="p1791836928165622"></a><a name="p1791836928165622"></a><a href="ifaddrs-h.md">ifaddrs.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p786422817165622"><a name="p786422817165622"></a><a name="p786422817165622"></a>Provides functions and data structures related to network operations. </p>
</td>
</tr>
<tr id="row1319404867165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1656864979165622"><a name="p1656864979165622"></a><a name="p1656864979165622"></a><a href="if-h.md">if.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p258546701165622"><a name="p258546701165622"></a><a name="p258546701165622"></a>Provides functions and data structures related to network operations. For example, you can use the functions to send and receive network data, manage network addresses, and convert bytes. </p>
</td>
</tr>
<tr id="row1159423736165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1973409769165622"><a name="p1973409769165622"></a><a name="p1973409769165622"></a><a href="netdb-h.md">netdb.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1606508917165622"><a name="p1606508917165622"></a><a name="p1606508917165622"></a>Provides functions and data structures related to network operations. For example, you can use the functions to send and receive network data, manage network addresses, and convert bytes. </p>
</td>
</tr>
<tr id="row1440403075165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p50898764165622"><a name="p50898764165622"></a><a name="p50898764165622"></a><a href="ether-h.md">ether.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p583771075165622"><a name="p583771075165622"></a><a name="p583771075165622"></a>Provides functions and data structures related to network operations. For example, you can use the functions to send and receive network data, manage network addresses, and convert bytes. </p>
</td>
</tr>
<tr id="row1254727466165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p731130353165622"><a name="p731130353165622"></a><a name="p731130353165622"></a><a href="ethernet-h.md">ethernet.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1573618006165622"><a name="p1573618006165622"></a><a name="p1573618006165622"></a>Declares the structures related to an Ethernet address. </p>
</td>
</tr>
<tr id="row1816439877165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1829863436165622"><a name="p1829863436165622"></a><a name="p1829863436165622"></a><a href="in-h.md">in.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p718374677165622"><a name="p718374677165622"></a><a name="p718374677165622"></a>Declares the data structures and macros related to network operations. </p>
</td>
</tr>
<tr id="row519681782165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2016129605165622"><a name="p2016129605165622"></a><a name="p2016129605165622"></a><a href="resolv-h.md">resolv.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p580098817165622"><a name="p580098817165622"></a><a name="p580098817165622"></a>Provides functions and data structures related to network operations. For example, you can use the functions to send and receive network data, manage network addresses, and convert bytes. </p>
</td>
</tr>
<tr id="row458835675165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1595416416165622"><a name="p1595416416165622"></a><a name="p1595416416165622"></a><a href="socket-h.md">socket.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2041398561165622"><a name="p2041398561165622"></a><a name="p2041398561165622"></a>Declares functions and data structures related to network sockets. </p>
</td>
</tr>
</tbody>
</table>

## Data Structures<a name="nested-classes"></a>

<a name="table1205584521165622"></a>
<table><thead align="left"><tr id="row117631187165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2103539303165622"><a name="p2103539303165622"></a><a name="p2103539303165622"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1490605425165622"><a name="p1490605425165622"></a><a name="p1490605425165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row530969374165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1298823926165622"><a name="p1298823926165622"></a><a name="p1298823926165622"></a><a href="ifaddrs.md">ifaddrs</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1047715094165622"><a name="p1047715094165622"></a><a name="p1047715094165622"></a>Defines the network interface information. </p>
</td>
</tr>
<tr id="row1736541374165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1656678650165622"><a name="p1656678650165622"></a><a name="p1656678650165622"></a><a href="if_nameindex.md">if_nameindex</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p6876265165622"><a name="p6876265165622"></a><a name="p6876265165622"></a>Defines the network adapter information. </p>
</td>
</tr>
<tr id="row367014446165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1717866646165622"><a name="p1717866646165622"></a><a name="p1717866646165622"></a><a href="hostent.md">hostent</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p225581485165622"><a name="p225581485165622"></a><a name="p225581485165622"></a>Describes the host name and address information. </p>
</td>
</tr>
<tr id="row814393709165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1681322427165622"><a name="p1681322427165622"></a><a name="p1681322427165622"></a><a href="protoent.md">protoent</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p785537657165622"><a name="p785537657165622"></a><a name="p785537657165622"></a>Describes the protocol database information. </p>
</td>
</tr>
<tr id="row1811290928165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2086714069165622"><a name="p2086714069165622"></a><a name="p2086714069165622"></a><a href="ether_addr.md">ether_addr</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2048281785165622"><a name="p2048281785165622"></a><a name="p2048281785165622"></a>Defines the information about a 48-bit Ethernet address. </p>
</td>
</tr>
<tr id="row80265396165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p10942294165622"><a name="p10942294165622"></a><a name="p10942294165622"></a><a href="in_addr.md">in_addr</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2076793408165622"><a name="p2076793408165622"></a><a name="p2076793408165622"></a>Describes the network address information. </p>
</td>
</tr>
<tr id="row1152981800165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p694916480165622"><a name="p694916480165622"></a><a name="p694916480165622"></a><a href="sockaddr.md">sockaddr</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1531456401165622"><a name="p1531456401165622"></a><a name="p1531456401165622"></a>Describes the socket address information. </p>
</td>
</tr>
</tbody>
</table>

## Macros<a name="define-members"></a>

<a name="table1878915825165622"></a>
<table><thead align="left"><tr id="row1954415074165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1209203763165622"><a name="p1209203763165622"></a><a name="p1209203763165622"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p954519540165622"><a name="p954519540165622"></a><a name="p954519540165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1219765898165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1931592665165622"><a name="p1931592665165622"></a><a name="p1931592665165622"></a><em id="ga4d04a8261523c8f3473946257c12ce5b"><a name="ga4d04a8261523c8f3473946257c12ce5b"></a><a name="ga4d04a8261523c8f3473946257c12ce5b"></a></em>h_addr    h_addr_list[0]</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p937903993165622"><a name="p937903993165622"></a><a name="p937903993165622"></a>Defines the first address in <strong id="b291770861165622"><a name="b291770861165622"></a><a name="b291770861165622"></a>h_addr_list</strong> for compatibility. </p>
</td>
</tr>
<tr id="row1612751741165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p517692029165622"><a name="p517692029165622"></a><a name="p517692029165622"></a><em id="ga9822d89774e0d6ddaa06503950130423"><a name="ga9822d89774e0d6ddaa06503950130423"></a><a name="ga9822d89774e0d6ddaa06503950130423"></a></em>ETH_ALEN    6</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2009372535165622"><a name="p2009372535165622"></a><a name="p2009372535165622"></a>Defines the length of an Ethernet address. </p>
</td>
</tr>
<tr id="row1633394005165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1087600243165622"><a name="p1087600243165622"></a><a name="p1087600243165622"></a><em id="gaf1c8cf84ac37451afaef3bde9976b6e1"><a name="gaf1c8cf84ac37451afaef3bde9976b6e1"></a><a name="gaf1c8cf84ac37451afaef3bde9976b6e1"></a></em>SHUT_RD    0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1629252871165622"><a name="p1629252871165622"></a><a name="p1629252871165622"></a>Disables reading data from a socket. </p>
</td>
</tr>
<tr id="row939995097165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1064672113165622"><a name="p1064672113165622"></a><a name="p1064672113165622"></a><em id="gaddb0a758e6fafdd89f5b7120f84738eb"><a name="gaddb0a758e6fafdd89f5b7120f84738eb"></a><a name="gaddb0a758e6fafdd89f5b7120f84738eb"></a></em>SHUT_WR    1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p855111551165622"><a name="p855111551165622"></a><a name="p855111551165622"></a>Disables writing data to a socket. </p>
</td>
</tr>
<tr id="row2000385472165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p162721155165622"><a name="p162721155165622"></a><a name="p162721155165622"></a><em id="ga80c54d1399557c97a0c81a319d08e9db"><a name="ga80c54d1399557c97a0c81a319d08e9db"></a><a name="ga80c54d1399557c97a0c81a319d08e9db"></a></em>SHUT_RDWR    2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1314472867165622"><a name="p1314472867165622"></a><a name="p1314472867165622"></a>Disables reading data from and writing data to a socket. </p>
</td>
</tr>
<tr id="row761492398165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p850895392165622"><a name="p850895392165622"></a><a name="p850895392165622"></a><em id="ga3f5da0b5be27fe31ec7cc11bfa8d1a25"><a name="ga3f5da0b5be27fe31ec7cc11bfa8d1a25"></a><a name="ga3f5da0b5be27fe31ec7cc11bfa8d1a25"></a></em>PF_INET    2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1868076717165622"><a name="p1868076717165622"></a><a name="p1868076717165622"></a>Defines the IPv4 internet protocol family. </p>
</td>
</tr>
<tr id="row508657345165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1509648040165622"><a name="p1509648040165622"></a><a name="p1509648040165622"></a><em id="ga323f2649198fc7e64b19881869265618"><a name="ga323f2649198fc7e64b19881869265618"></a><a name="ga323f2649198fc7e64b19881869265618"></a></em>PF_INET6    10</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1263592930165622"><a name="p1263592930165622"></a><a name="p1263592930165622"></a>Defines the IPv6 internet protocol family. </p>
</td>
</tr>
<tr id="row1219080647165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p764275777165622"><a name="p764275777165622"></a><a name="p764275777165622"></a><em id="ga9930604d0e32588eae76f43ca38e7826"><a name="ga9930604d0e32588eae76f43ca38e7826"></a><a name="ga9930604d0e32588eae76f43ca38e7826"></a></em>AF_INET    <a href="NET.md#ga3f5da0b5be27fe31ec7cc11bfa8d1a25">PF_INET</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p518549552165622"><a name="p518549552165622"></a><a name="p518549552165622"></a>Defines the IPv4 internet address. </p>
</td>
</tr>
<tr id="row889071940165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1617935234165622"><a name="p1617935234165622"></a><a name="p1617935234165622"></a><em id="gaa03706b2738b9a58d4985dfbe99e1bac"><a name="gaa03706b2738b9a58d4985dfbe99e1bac"></a><a name="gaa03706b2738b9a58d4985dfbe99e1bac"></a></em>AF_INET6    <a href="NET.md#ga323f2649198fc7e64b19881869265618">PF_INET6</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1827943514165622"><a name="p1827943514165622"></a><a name="p1827943514165622"></a>Defines the IPv6 internet address. </p>
</td>
</tr>
<tr id="row30356415165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p475588498165622"><a name="p475588498165622"></a><a name="p475588498165622"></a><em id="ga249394484f9410a2e3f8eba24657feb9"><a name="ga249394484f9410a2e3f8eba24657feb9"></a><a name="ga249394484f9410a2e3f8eba24657feb9"></a></em>SOCK_STREAM    1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1777656363165622"><a name="p1777656363165622"></a><a name="p1777656363165622"></a>Defines stream sockets. </p>
</td>
</tr>
<tr id="row1161312834165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1720307768165622"><a name="p1720307768165622"></a><a name="p1720307768165622"></a><em id="ga4db8b9a846c67404db0b6f014f9a9fdf"><a name="ga4db8b9a846c67404db0b6f014f9a9fdf"></a><a name="ga4db8b9a846c67404db0b6f014f9a9fdf"></a></em>SOCK_DGRAM    2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p996061154165622"><a name="p996061154165622"></a><a name="p996061154165622"></a>Defines datagram sockets. </p>
</td>
</tr>
<tr id="row1231694521165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1630561802165622"><a name="p1630561802165622"></a><a name="p1630561802165622"></a><em id="ga346f84e37c42f88e91e7304c3d77fde8"><a name="ga346f84e37c42f88e91e7304c3d77fde8"></a><a name="ga346f84e37c42f88e91e7304c3d77fde8"></a></em>SOCK_RAW    3</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p265987800165622"><a name="p265987800165622"></a><a name="p265987800165622"></a>Defines raw sockets. </p>
</td>
</tr>
<tr id="row689188383165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1515808344165622"><a name="p1515808344165622"></a><a name="p1515808344165622"></a><em id="gab18d3d439e4a9c8d0f73e7166e8eb376"><a name="gab18d3d439e4a9c8d0f73e7166e8eb376"></a><a name="gab18d3d439e4a9c8d0f73e7166e8eb376"></a></em>MSG_DONTWAIT    0x0040</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p954733989165622"><a name="p954733989165622"></a><a name="p954733989165622"></a>Defines the message type of a non-blocking operation. </p>
</td>
</tr>
<tr id="row1428277829165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p307939785165622"><a name="p307939785165622"></a><a name="p307939785165622"></a><em id="ga9f55d0e90dc8cc6b2287312435cdde48"><a name="ga9f55d0e90dc8cc6b2287312435cdde48"></a><a name="ga9f55d0e90dc8cc6b2287312435cdde48"></a></em>MSG_NOSIGNAL    0x4000</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1081740114165622"><a name="p1081740114165622"></a><a name="p1081740114165622"></a>Defines the message type that does not generate a signal. </p>
</td>
</tr>
<tr id="row1606962633165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p536233192165622"><a name="p536233192165622"></a><a name="p536233192165622"></a><em id="ga7b7c7e5e523ff0fc8823e7bff7665ead"><a name="ga7b7c7e5e523ff0fc8823e7bff7665ead"></a><a name="ga7b7c7e5e523ff0fc8823e7bff7665ead"></a></em>MSG_MORE    0x8000</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p426545960165622"><a name="p426545960165622"></a><a name="p426545960165622"></a>Defines the message type that more data is to be transferred. </p>
</td>
</tr>
<tr id="row1494763362165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p313791995165622"><a name="p313791995165622"></a><a name="p313791995165622"></a><em id="ga8ab1e00e94a92737d3a4b407f7fa90f1"><a name="ga8ab1e00e94a92737d3a4b407f7fa90f1"></a><a name="ga8ab1e00e94a92737d3a4b407f7fa90f1"></a></em>SO_TYPE    3</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p967200535165622"><a name="p967200535165622"></a><a name="p967200535165622"></a>Obtains the socket type. </p>
</td>
</tr>
<tr id="row1635382974165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p496403569165622"><a name="p496403569165622"></a><a name="p496403569165622"></a><em id="ga4a6d9f7ea4bf046c50102c17ba1faf37"><a name="ga4a6d9f7ea4bf046c50102c17ba1faf37"></a><a name="ga4a6d9f7ea4bf046c50102c17ba1faf37"></a></em>SO_DONTROUTE    5</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1140822677165622"><a name="p1140822677165622"></a><a name="p1140822677165622"></a>Prohibits messages from being sent via a gateway. </p>
</td>
</tr>
<tr id="row2067743539165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p927910986165622"><a name="p927910986165622"></a><a name="p927910986165622"></a><em id="gad05e5d66b4608d73747c4a10b802a737"><a name="gad05e5d66b4608d73747c4a10b802a737"></a><a name="gad05e5d66b4608d73747c4a10b802a737"></a></em>SO_BROADCAST    6</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p336665282165622"><a name="p336665282165622"></a><a name="p336665282165622"></a>Enables sending broadcast messages. </p>
</td>
</tr>
<tr id="row711918969165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p117301227165622"><a name="p117301227165622"></a><a name="p117301227165622"></a><em id="gaf618cbb85161ff3196d3bcdf7565ba64"><a name="gaf618cbb85161ff3196d3bcdf7565ba64"></a><a name="gaf618cbb85161ff3196d3bcdf7565ba64"></a></em>SO_SNDBUF    7</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1771276537165622"><a name="p1771276537165622"></a><a name="p1771276537165622"></a>Defines the size of the socket sending buffer, in bytes. </p>
</td>
</tr>
<tr id="row265773982165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p866854907165622"><a name="p866854907165622"></a><a name="p866854907165622"></a><em id="ga0db12e960ac303030400d9fd95391b52"><a name="ga0db12e960ac303030400d9fd95391b52"></a><a name="ga0db12e960ac303030400d9fd95391b52"></a></em>SO_RCVBUF    8</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p522382575165622"><a name="p522382575165622"></a><a name="p522382575165622"></a>Defines the size of the socket receiving buffer, in bytes. </p>
</td>
</tr>
<tr id="row1359075206165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1221266196165622"><a name="p1221266196165622"></a><a name="p1221266196165622"></a><em id="gaf2d1ed6a34336a6f3df80fb518325846"><a name="gaf2d1ed6a34336a6f3df80fb518325846"></a><a name="gaf2d1ed6a34336a6f3df80fb518325846"></a></em>SO_RCVTIMEO    66</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p147243465165622"><a name="p147243465165622"></a><a name="p147243465165622"></a>Defines the data receiving timeout interval. </p>
</td>
</tr>
<tr id="row1158371130165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1289489514165622"><a name="p1289489514165622"></a><a name="p1289489514165622"></a><em id="gab9d2f7ca5c94bd51cdab3e1913b66e2d"><a name="gab9d2f7ca5c94bd51cdab3e1913b66e2d"></a><a name="gab9d2f7ca5c94bd51cdab3e1913b66e2d"></a></em>SO_SNDTIMEO    67</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1992736991165622"><a name="p1992736991165622"></a><a name="p1992736991165622"></a>Defines the data sending timeout interval. </p>
</td>
</tr>
<tr id="row13965642165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p859201490165622"><a name="p859201490165622"></a><a name="p859201490165622"></a><em id="gae0339480fb8088046e6038ee1baf3a61"><a name="gae0339480fb8088046e6038ee1baf3a61"></a><a name="gae0339480fb8088046e6038ee1baf3a61"></a></em>SO_BINDTODEVICE    25</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1011338341165622"><a name="p1011338341165622"></a><a name="p1011338341165622"></a>Binds the socket to a particular device. </p>
</td>
</tr>
<tr id="row780228089165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1736732753165622"><a name="p1736732753165622"></a><a name="p1736732753165622"></a><em id="ga92d045f6ee2f343d6b28830a9fec082e"><a name="ga92d045f6ee2f343d6b28830a9fec082e"></a><a name="ga92d045f6ee2f343d6b28830a9fec082e"></a></em>SOL_SOCKET    1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1697406138165622"><a name="p1697406138165622"></a><a name="p1697406138165622"></a>Defines the layers of a socket. </p>
</td>
</tr>
</tbody>
</table>

## Typedefs<a name="typedef-members"></a>

<a name="table1759747206165622"></a>
<table><thead align="left"><tr id="row1698674105165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p355592800165622"><a name="p355592800165622"></a><a name="p355592800165622"></a>Typedef Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1491312429165622"><a name="p1491312429165622"></a><a name="p1491312429165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row222003021165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1401004131165622"><a name="p1401004131165622"></a><a name="p1401004131165622"></a>in_addr_t </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1635505969165622"><a name="p1635505969165622"></a><a name="p1635505969165622"></a><strong id="ga98b38134a62f24554da0ffcabde8062c"><a name="ga98b38134a62f24554da0ffcabde8062c"></a><a name="ga98b38134a62f24554da0ffcabde8062c"></a></strong> typedef uint32_t </p>
<p id="p1463317896165622"><a name="p1463317896165622"></a><a name="p1463317896165622"></a>Defines the data type of a network address. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table1417697405165622"></a>
<table><thead align="left"><tr id="row335501253165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1840091401165622"><a name="p1840091401165622"></a><a name="p1840091401165622"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p531314485165622"><a name="p531314485165622"></a><a name="p531314485165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row914131917165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p268929525165622"><a name="p268929525165622"></a><a name="p268929525165622"></a><a href="NET.md#gac7eed08cd3b67f42bf56063157c8fd55">htonl</a> (uint32_t n)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p804783579165622"><a name="p804783579165622"></a><a name="p804783579165622"></a>uint32_t </p>
<p id="p1879869433165622"><a name="p1879869433165622"></a><a name="p1879869433165622"></a>Converts an integer from the host byte order to the network byte order. </p>
</td>
</tr>
<tr id="row1906759071165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1861190601165622"><a name="p1861190601165622"></a><a name="p1861190601165622"></a><a href="NET.md#gaabce0f8d453c3380e5b8a3d4947eb48c">htons</a> (uint16_t n)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p993122829165622"><a name="p993122829165622"></a><a name="p993122829165622"></a>uint16_t </p>
<p id="p643737269165622"><a name="p643737269165622"></a><a name="p643737269165622"></a>Converts a 16-bit integer from the host byte order to the network byte order. </p>
</td>
</tr>
<tr id="row1994930838165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1872084599165622"><a name="p1872084599165622"></a><a name="p1872084599165622"></a><a href="NET.md#gae68530d41f32dfef707f20b2bbaa5a44">ntohl</a> (uint32_t n)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1061647041165622"><a name="p1061647041165622"></a><a name="p1061647041165622"></a>uint32_t </p>
<p id="p62974612165622"><a name="p62974612165622"></a><a name="p62974612165622"></a>Converts an integer from the network byte order to the host byte order. </p>
</td>
</tr>
<tr id="row1729526964165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p411981076165622"><a name="p411981076165622"></a><a name="p411981076165622"></a><a href="NET.md#gaf8c87af507c59bd8fef112e5e35fe537">ntohs</a> (uint16_t n)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p193948792165622"><a name="p193948792165622"></a><a name="p193948792165622"></a>uint16_t </p>
<p id="p1134956015165622"><a name="p1134956015165622"></a><a name="p1134956015165622"></a>Converts a 16-bit integer from the network byte order to the host byte order. </p>
</td>
</tr>
<tr id="row578425397165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p213052163165622"><a name="p213052163165622"></a><a name="p213052163165622"></a><a href="NET.md#ga617651ec952a1f4c9cbddbf78f4b2e2e">inet_addr</a> (const char *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1597112219165622"><a name="p1597112219165622"></a><a name="p1597112219165622"></a><a href="NET.md#ga98b38134a62f24554da0ffcabde8062c">in_addr_t</a> </p>
<p id="p1128117211165622"><a name="p1128117211165622"></a><a name="p1128117211165622"></a>Converts a string from the IPv4 numbers-and-dots notation to the binary data in network byte order. </p>
</td>
</tr>
<tr id="row681971631165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p398622306165622"><a name="p398622306165622"></a><a name="p398622306165622"></a><a href="NET.md#ga6f478437c4810fce89cf0e77d94181f8">inet_network</a> (const char *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1381399040165622"><a name="p1381399040165622"></a><a name="p1381399040165622"></a><a href="NET.md#ga98b38134a62f24554da0ffcabde8062c">in_addr_t</a> </p>
<p id="p2130434117165622"><a name="p2130434117165622"></a><a name="p2130434117165622"></a>Converts a string from the IPv4 numbers-and-dots notation to the binary data in host byte order. </p>
</td>
</tr>
<tr id="row1491783927165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p112190338165622"><a name="p112190338165622"></a><a name="p112190338165622"></a><a href="NET.md#ga08b9fff487151e004d9862cbf34a51ad">inet_ntoa</a> (struct <a href="in_addr.md">in_addr</a> in)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1977891491165622"><a name="p1977891491165622"></a><a name="p1977891491165622"></a>char * </p>
<p id="p2032447450165622"><a name="p2032447450165622"></a><a name="p2032447450165622"></a>Converts a network address to a string in dotted-decimal format. </p>
</td>
</tr>
<tr id="row354539188165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1115661129165622"><a name="p1115661129165622"></a><a name="p1115661129165622"></a><a href="NET.md#ga3f6e2b2dae98a409d77c6e3b0cebc04b">inet_pton</a> (int af, const char *__restrict s, void *__restrict a0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1405281286165622"><a name="p1405281286165622"></a><a name="p1405281286165622"></a>int </p>
<p id="p391360370165622"><a name="p391360370165622"></a><a name="p391360370165622"></a>Converts a string to a network address in the specified address family. </p>
</td>
</tr>
<tr id="row414525027165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2063423860165622"><a name="p2063423860165622"></a><a name="p2063423860165622"></a><a href="NET.md#gae9a2182ca3255f16723adeea14665b55">inet_ntop</a> (int af, const void *restrict a0, char *restrict s, <a href="UTILS.md#ga531675af4e35aaa1cc9aeefa6cc2ccc4">socklen_t</a> l)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1057513689165622"><a name="p1057513689165622"></a><a name="p1057513689165622"></a>const char * </p>
<p id="p1687013736165622"><a name="p1687013736165622"></a><a name="p1687013736165622"></a>Converts a network address in the specified address family to a string. </p>
</td>
</tr>
<tr id="row1274515079165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1215974627165622"><a name="p1215974627165622"></a><a name="p1215974627165622"></a><a href="NET.md#ga26ee8e8e3949699a9c0e02ece272d370">inet_aton</a> (const char *s0, struct <a href="in_addr.md">in_addr</a> *dest)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1058586056165622"><a name="p1058586056165622"></a><a name="p1058586056165622"></a>int </p>
<p id="p820297571165622"><a name="p820297571165622"></a><a name="p820297571165622"></a>Converts an IP address from the string format to the 32-bit binary format in network byte order. </p>
</td>
</tr>
<tr id="row1969308572165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1966219432165622"><a name="p1966219432165622"></a><a name="p1966219432165622"></a><a href="NET.md#gab28732d1d740597f53fb65a09d97800c">inet_makeaddr</a> (<a href="NET.md#ga98b38134a62f24554da0ffcabde8062c">in_addr_t</a> n, <a href="NET.md#ga98b38134a62f24554da0ffcabde8062c">in_addr_t</a> h)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p530837493165622"><a name="p530837493165622"></a><a name="p530837493165622"></a>struct <a href="in_addr.md">in_addr</a> </p>
<p id="p1251337543165622"><a name="p1251337543165622"></a><a name="p1251337543165622"></a>Converts the network number and host address to the network address. </p>
</td>
</tr>
<tr id="row1833985546165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1444538270165622"><a name="p1444538270165622"></a><a name="p1444538270165622"></a><a href="NET.md#ga1facb1380b7657ca9c72fb2633b60e3b">inet_lnaof</a> (struct <a href="in_addr.md">in_addr</a> in)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1167912162165622"><a name="p1167912162165622"></a><a name="p1167912162165622"></a><a href="NET.md#ga98b38134a62f24554da0ffcabde8062c">in_addr_t</a> </p>
<p id="p403988410165622"><a name="p403988410165622"></a><a name="p403988410165622"></a>Converts an IP address into a host ID in host byte order without network bits. </p>
</td>
</tr>
<tr id="row1193591676165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p764783135165622"><a name="p764783135165622"></a><a name="p764783135165622"></a><a href="NET.md#ga3a96aa4e6abe8e6959ea63fe338174dd">inet_netof</a> (struct <a href="in_addr.md">in_addr</a> in)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1710533175165622"><a name="p1710533175165622"></a><a name="p1710533175165622"></a><a href="NET.md#ga98b38134a62f24554da0ffcabde8062c">in_addr_t</a> </p>
<p id="p771466745165622"><a name="p771466745165622"></a><a name="p771466745165622"></a>Extracts the network number from the <strong id="b202325792165622"><a name="b202325792165622"></a><a name="b202325792165622"></a><a href="in_addr.md">in_addr</a></strong> structure and converts it to the host byte order. </p>
</td>
</tr>
<tr id="row1237780484165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p476778450165622"><a name="p476778450165622"></a><a name="p476778450165622"></a><a href="NET.md#gabfdd6ca5469fe73ed88ba94bf8db57cc">freeifaddrs</a> (struct <a href="ifaddrs.md">ifaddrs</a> *ifp)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p363972402165622"><a name="p363972402165622"></a><a name="p363972402165622"></a>void </p>
<p id="p1101829015165622"><a name="p1101829015165622"></a><a name="p1101829015165622"></a>Frees the network interface information obtained by <strong id="b1828124601165622"><a name="b1828124601165622"></a><a name="b1828124601165622"></a>getifaddrs</strong>. </p>
</td>
</tr>
<tr id="row2019954300165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1876743359165622"><a name="p1876743359165622"></a><a name="p1876743359165622"></a><a href="NET.md#ga7fe55c04ac2116fa501338fdcb279cc9">if_freenameindex</a> (struct <a href="if_nameindex.md">if_nameindex</a> *idx)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1400710803165622"><a name="p1400710803165622"></a><a name="p1400710803165622"></a>void </p>
<p id="p1768261155165622"><a name="p1768261155165622"></a><a name="p1768261155165622"></a>Frees the network adapter information obtained by <a href="if_nameindex.md">if_nameindex</a>. </p>
</td>
</tr>
<tr id="row1356015958165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1480035366165622"><a name="p1480035366165622"></a><a name="p1480035366165622"></a><a href="NET.md#ga6a806414e4ae5bffb09e3a1d25d8db75">setprotoent</a> (int stayopen)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p138921835165622"><a name="p138921835165622"></a><a name="p138921835165622"></a>void </p>
<p id="p1957501441165622"><a name="p1957501441165622"></a><a name="p1957501441165622"></a>Opens a connection to the database and sets the next entry to the first entry. </p>
</td>
</tr>
<tr id="row796162113165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1072903239165622"><a name="p1072903239165622"></a><a name="p1072903239165622"></a><a href="NET.md#gaca0da70657afbc3e723990bb229deec3">getprotoent</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p963542963165622"><a name="p963542963165622"></a><a name="p963542963165622"></a>struct <a href="protoent.md">protoent</a> * </p>
<p id="p1395399582165622"><a name="p1395399582165622"></a><a name="p1395399582165622"></a>Retrieves the current protocol information. </p>
</td>
</tr>
<tr id="row1014555395165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2000567555165622"><a name="p2000567555165622"></a><a name="p2000567555165622"></a><a href="NET.md#ga83ac8a97dd9d895cda658af3aa46fd55">getprotobyname</a> (const char *name)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1694459066165622"><a name="p1694459066165622"></a><a name="p1694459066165622"></a>struct <a href="protoent.md">protoent</a> * </p>
<p id="p1720066241165622"><a name="p1720066241165622"></a><a name="p1720066241165622"></a>Retrieves the information about a specified protocol. </p>
</td>
</tr>
<tr id="row299607733165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1237422579165622"><a name="p1237422579165622"></a><a name="p1237422579165622"></a><a href="NET.md#gac01697dc4a5b8e434522220913bd46ea">getprotobynumber</a> (int num)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p195797413165622"><a name="p195797413165622"></a><a name="p195797413165622"></a>struct <a href="protoent.md">protoent</a> * </p>
<p id="p1902863525165622"><a name="p1902863525165622"></a><a name="p1902863525165622"></a>Retrieves the information about a protocol with the specified number. </p>
</td>
</tr>
<tr id="row339478267165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1852547050165622"><a name="p1852547050165622"></a><a name="p1852547050165622"></a><a href="NET.md#gaa68de2578d4e0849f82d70b2f5b9af70">herror</a> (const char *msg)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p716942693165622"><a name="p716942693165622"></a><a name="p716942693165622"></a>void </p>
<p id="p1327700841165622"><a name="p1327700841165622"></a><a name="p1327700841165622"></a>Prints error information. </p>
</td>
</tr>
<tr id="row565246483165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p342960320165622"><a name="p342960320165622"></a><a name="p342960320165622"></a><a href="NET.md#gac1752c48d9cf2ff87e29f29df6caa585">hstrerror</a> (int ecode)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p768209359165622"><a name="p768209359165622"></a><a name="p768209359165622"></a>const char * </p>
<p id="p842163866165622"><a name="p842163866165622"></a><a name="p842163866165622"></a>Retrieves error information associated with the specified error number. </p>
</td>
</tr>
<tr id="row1251131427165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p131967471165622"><a name="p131967471165622"></a><a name="p131967471165622"></a><a href="NET.md#ga07e34e6ee9e272c4799780915d11677c">ether_ntoa</a> (const struct <a href="ether_addr.md">ether_addr</a> *p_a)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1504142721165622"><a name="p1504142721165622"></a><a name="p1504142721165622"></a>char * </p>
<p id="p272331561165622"><a name="p272331561165622"></a><a name="p272331561165622"></a>Converts binary data in network byte order into a standard 48-bit Ethernet host address in the colon hexadecimal notation. </p>
</td>
</tr>
<tr id="row230866838165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p761553735165622"><a name="p761553735165622"></a><a name="p761553735165622"></a><a href="NET.md#gaab4c5b65c36fc0ea96a017daabc3770a">ether_aton</a> (const char *x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1764116744165622"><a name="p1764116744165622"></a><a name="p1764116744165622"></a>struct <a href="ether_addr.md">ether_addr</a> * </p>
<p id="p1305611615165622"><a name="p1305611615165622"></a><a name="p1305611615165622"></a>Converts a standard 48-bit Ethernet host address in the colon hexadecimal notation into binary data in network byte order. </p>
</td>
</tr>
<tr id="row1413192238165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p857426260165622"><a name="p857426260165622"></a><a name="p857426260165622"></a><a href="NET.md#ga245e21de8e82756712a5182c2674c2ad">ether_ntoa_r</a> (const struct <a href="ether_addr.md">ether_addr</a> *p_a, char *x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1938088519165622"><a name="p1938088519165622"></a><a name="p1938088519165622"></a>char * </p>
<p id="p167932703165622"><a name="p167932703165622"></a><a name="p167932703165622"></a>Converts binary data in network byte order into a standard 48-bit Ethernet host address in the colon hexadecimal notation. This function is reentrant. </p>
</td>
</tr>
<tr id="row152922259165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1674447150165622"><a name="p1674447150165622"></a><a name="p1674447150165622"></a><a href="NET.md#gac0954821754bace30f674e61bb9f4e5f">ether_aton_r</a> (const char *x, struct <a href="ether_addr.md">ether_addr</a> *p_a)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p795525840165622"><a name="p795525840165622"></a><a name="p795525840165622"></a>struct <a href="ether_addr.md">ether_addr</a> * </p>
<p id="p1558631953165622"><a name="p1558631953165622"></a><a name="p1558631953165622"></a>Converts a standard 48-bit Ethernet host address in the colon hexadecimal notation into binary data in network byte order. This function is reentrant. </p>
</td>
</tr>
<tr id="row1240904431165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2057695536165622"><a name="p2057695536165622"></a><a name="p2057695536165622"></a><a href="NET.md#ga0438570faf515401bffa1a0d9c94a266">dn_comp</a> (const char *src, unsigned char *dst, int space, unsigned char **dnptrs, unsigned char **lastdnptr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1852356968165622"><a name="p1852356968165622"></a><a name="p1852356968165622"></a>int </p>
<p id="p1535555058165622"><a name="p1535555058165622"></a><a name="p1535555058165622"></a>Compresses a network domain name. </p>
</td>
</tr>
<tr id="row574151719165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p796146780165622"><a name="p796146780165622"></a><a name="p796146780165622"></a><a href="NET.md#ga91eb2055a64b28e4942a3a760d747243">dn_expand</a> (const unsigned char *base, const unsigned char *end, const unsigned char *src, char *dest, int space)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p454131952165622"><a name="p454131952165622"></a><a name="p454131952165622"></a>int </p>
<p id="p912478488165622"><a name="p912478488165622"></a><a name="p912478488165622"></a>Expands a compressed domain name to a full domain name. </p>
</td>
</tr>
<tr id="row1176354603165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1631353978165622"><a name="p1631353978165622"></a><a name="p1631353978165622"></a><a href="NET.md#gaf4e0711877c45a41168ac677b0670ccd">socket</a> (int domain, int type, int protocol)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1678616123165622"><a name="p1678616123165622"></a><a name="p1678616123165622"></a>int </p>
<p id="p1445236515165622"><a name="p1445236515165622"></a><a name="p1445236515165622"></a>Creates a socket and returns its descriptor. </p>
</td>
</tr>
<tr id="row1513001435165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1159788649165622"><a name="p1159788649165622"></a><a name="p1159788649165622"></a><a href="NET.md#ga402425b8e1ceab40ac38a949babcf1aa">shutdown</a> (int sockfd, int how)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1852276795165622"><a name="p1852276795165622"></a><a name="p1852276795165622"></a>int </p>
<p id="p595527931165622"><a name="p595527931165622"></a><a name="p595527931165622"></a>Shuts down a socket. </p>
</td>
</tr>
<tr id="row697204140165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1873439718165622"><a name="p1873439718165622"></a><a name="p1873439718165622"></a><a href="NET.md#ga82199bcd81894331533a25f08e172480">bind</a> (int sockfd, const struct <a href="sockaddr.md">sockaddr</a> *addr, <a href="UTILS.md#ga531675af4e35aaa1cc9aeefa6cc2ccc4">socklen_t</a> addrlen)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p655989313165622"><a name="p655989313165622"></a><a name="p655989313165622"></a>int </p>
<p id="p1038762382165622"><a name="p1038762382165622"></a><a name="p1038762382165622"></a>Binds a local protocol address to a socket. </p>
</td>
</tr>
<tr id="row1361398919165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1607710504165622"><a name="p1607710504165622"></a><a name="p1607710504165622"></a><a href="NET.md#gacdfd99b6c59c833776412fbb0c539efb">connect</a> (int sockfd, const struct <a href="sockaddr.md">sockaddr</a> *addr, <a href="UTILS.md#ga531675af4e35aaa1cc9aeefa6cc2ccc4">socklen_t</a> addrlen)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2021029970165622"><a name="p2021029970165622"></a><a name="p2021029970165622"></a>int </p>
<p id="p590240563165622"><a name="p590240563165622"></a><a name="p590240563165622"></a>Connects a socket to the specified address. </p>
</td>
</tr>
<tr id="row648581087165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1656893865165622"><a name="p1656893865165622"></a><a name="p1656893865165622"></a><a href="NET.md#ga5989c21d05cb17caba26cef496a7beea">listen</a> (int sockfd, int backlog)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p117601069165622"><a name="p117601069165622"></a><a name="p117601069165622"></a>int </p>
<p id="p1659558924165622"><a name="p1659558924165622"></a><a name="p1659558924165622"></a>Listens for network connection requests on a socket. </p>
</td>
</tr>
<tr id="row1917756621165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2070097199165622"><a name="p2070097199165622"></a><a name="p2070097199165622"></a><a href="NET.md#ga0807af5ac9dfc2a63624e8c3e0ae95ef">accept</a> (int sockfd, struct <a href="sockaddr.md">sockaddr</a> *__restrict addr, <a href="UTILS.md#ga531675af4e35aaa1cc9aeefa6cc2ccc4">socklen_t</a> *__restrict addrlen)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1915891437165622"><a name="p1915891437165622"></a><a name="p1915891437165622"></a>int </p>
<p id="p644031068165622"><a name="p644031068165622"></a><a name="p644031068165622"></a>Accepts a connection request on a socket. </p>
</td>
</tr>
<tr id="row590963290165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p66547692165622"><a name="p66547692165622"></a><a name="p66547692165622"></a><a href="NET.md#ga62577da7dba23abb9c99cf5c2800ab24">getsockname</a> (int fd, struct <a href="sockaddr.md">sockaddr</a> *restrict addr, <a href="UTILS.md#ga531675af4e35aaa1cc9aeefa6cc2ccc4">socklen_t</a> *restrict len)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1193683614165622"><a name="p1193683614165622"></a><a name="p1193683614165622"></a>int </p>
<p id="p499125320165622"><a name="p499125320165622"></a><a name="p499125320165622"></a>Retrieves the local address of the specified socket. </p>
</td>
</tr>
<tr id="row741782488165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p82188271165622"><a name="p82188271165622"></a><a name="p82188271165622"></a><a href="NET.md#ga13d77555ad4ed62dfef0ce32dd16755c">getpeername</a> (int fd, struct <a href="sockaddr.md">sockaddr</a> *restrict addr, <a href="UTILS.md#ga531675af4e35aaa1cc9aeefa6cc2ccc4">socklen_t</a> *restrict len)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1474460988165622"><a name="p1474460988165622"></a><a name="p1474460988165622"></a>int </p>
<p id="p1518324996165622"><a name="p1518324996165622"></a><a name="p1518324996165622"></a>Retrieves the peer address of the specified socket. </p>
</td>
</tr>
<tr id="row1771763256165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p374630858165622"><a name="p374630858165622"></a><a name="p374630858165622"></a><a href="NET.md#ga4053f5c8e26fd490ef54e2a0abf5c89f">send</a> (int fd, const void *buf, size_t len, int flags)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1917686274165622"><a name="p1917686274165622"></a><a name="p1917686274165622"></a>ssize_t </p>
<p id="p1840439543165622"><a name="p1840439543165622"></a><a name="p1840439543165622"></a>Sends data to another socket. </p>
</td>
</tr>
<tr id="row1370643669165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1111186377165622"><a name="p1111186377165622"></a><a name="p1111186377165622"></a><a href="NET.md#ga5d049263cd0e3206b93530e68dfd7403">recv</a> (int fd, void *buf, size_t len, int flags)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p65473682165622"><a name="p65473682165622"></a><a name="p65473682165622"></a>ssize_t </p>
<p id="p171855263165622"><a name="p171855263165622"></a><a name="p171855263165622"></a>Receives data from another socket. </p>
</td>
</tr>
<tr id="row1910673505165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1552621304165622"><a name="p1552621304165622"></a><a name="p1552621304165622"></a><a href="NET.md#ga2587b27d2c6014c6b568a974655f41c5">sendto</a> (int fd, const void *buf, size_t len, int flags, const struct <a href="sockaddr.md">sockaddr</a> *addr, <a href="UTILS.md#ga531675af4e35aaa1cc9aeefa6cc2ccc4">socklen_t</a> alen)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1115305304165622"><a name="p1115305304165622"></a><a name="p1115305304165622"></a>ssize_t </p>
<p id="p1792323185165622"><a name="p1792323185165622"></a><a name="p1792323185165622"></a>Sends data to another socket. </p>
</td>
</tr>
<tr id="row1191891149165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2040445494165622"><a name="p2040445494165622"></a><a name="p2040445494165622"></a><a href="NET.md#ga3089d3ee59e26bd4def3ef870175540e">recvfrom</a> (int fd, void *__restrict buf, size_t len, int flags, struct <a href="sockaddr.md">sockaddr</a> *__restrict addr, <a href="UTILS.md#ga531675af4e35aaa1cc9aeefa6cc2ccc4">socklen_t</a> *__restrict alen)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p290540837165622"><a name="p290540837165622"></a><a name="p290540837165622"></a>ssize_t </p>
<p id="p236823125165622"><a name="p236823125165622"></a><a name="p236823125165622"></a>Receives data from a specified socket. </p>
</td>
</tr>
<tr id="row605845889165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1391655033165622"><a name="p1391655033165622"></a><a name="p1391655033165622"></a><a href="NET.md#ga70c97d3a1eab72cba4461d66a1778570">sendmsg</a> (int fd, const struct msghdr *msg, int flags)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1457360740165622"><a name="p1457360740165622"></a><a name="p1457360740165622"></a>ssize_t </p>
<p id="p275173990165622"><a name="p275173990165622"></a><a name="p275173990165622"></a>Sends data to another socket. </p>
</td>
</tr>
<tr id="row1972728063165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1206435914165622"><a name="p1206435914165622"></a><a name="p1206435914165622"></a><a href="NET.md#gaaba92f19a31c01b93e3391671a8b3dd5">recvmsg</a> (int fd, struct msghdr *msg, int flags)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2086291068165622"><a name="p2086291068165622"></a><a name="p2086291068165622"></a>ssize_t </p>
<p id="p415711003165622"><a name="p415711003165622"></a><a name="p415711003165622"></a>Receives data from a specified socket. </p>
</td>
</tr>
<tr id="row1845173267165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p429912961165622"><a name="p429912961165622"></a><a name="p429912961165622"></a><a href="NET.md#gacfcf672e255123afb75ed4d326257073">getsockopt</a> (int fd, int level, int optname, void *__restrict optval, <a href="UTILS.md#ga531675af4e35aaa1cc9aeefa6cc2ccc4">socklen_t</a> *__restrict optlen)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1455157354165622"><a name="p1455157354165622"></a><a name="p1455157354165622"></a>int </p>
<p id="p1924299632165622"><a name="p1924299632165622"></a><a name="p1924299632165622"></a>Retrieves the socket options. </p>
</td>
</tr>
<tr id="row342788381165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1242553578165622"><a name="p1242553578165622"></a><a name="p1242553578165622"></a><a href="NET.md#ga81983de50d79d797b2ac0f0d0f28953f">setsockopt</a> (int fd, int level, int optname, const void *optval, <a href="UTILS.md#ga531675af4e35aaa1cc9aeefa6cc2ccc4">socklen_t</a> optlen)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1870939022165622"><a name="p1870939022165622"></a><a name="p1870939022165622"></a>int </p>
<p id="p436414601165622"><a name="p436414601165622"></a><a name="p436414601165622"></a>Sets the socket options. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section2074466484165622"></a>

## **Function **<a name="section1845007127165622"></a>

## accept\(\)<a name="ga0807af5ac9dfc2a63624e8c3e0ae95ef"></a>

```
int accept (int sockfd, struct [sockaddr](sockaddr.md) *__restrict addr, [socklen_t](UTILS.md#ga531675af4e35aaa1cc9aeefa6cc2ccc4) *__restrict addrlen )
```

 **Description:**

Accepts a connection request on a socket. 

This function is used for waiting for a connection request from the client and for TCP only. 

**Parameters:**

<a name="table1107561503165622"></a>
<table><thead align="left"><tr id="row2033229044165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p885217694165622"><a name="p885217694165622"></a><a name="p885217694165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p147911679165622"><a name="p147911679165622"></a><a name="p147911679165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row205923620165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sockfd</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the socket descriptor. </td>
</tr>
<tr id="row1752162914165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">addr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the socket address requiring for the connection. </td>
</tr>
<tr id="row1695879196165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">addrlen</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the length of the address structure pointed to by <strong id="b1563435045165622"><a name="b1563435045165622"></a><a name="b1563435045165622"></a>addr</strong>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns a valid socket if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails. 

<a name="table130175577165622"></a>
<table><thead align="left"><tr id="row1358598457165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p300936925165622"><a name="p300936925165622"></a><a name="p300936925165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1956609066165622"><a name="p1956609066165622"></a><a name="p1956609066165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row658912739165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1978206340165622"><a name="p1978206340165622"></a><a name="p1978206340165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1277096387165622"><a name="p1277096387165622"></a><a name="p1277096387165622"></a>Invalid input parameter </p>
</td>
</tr>
<tr id="row1357681578165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p576550468165622"><a name="p576550468165622"></a><a name="p576550468165622"></a>EOPNOTSUPP </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1036431939165622"><a name="p1036431939165622"></a><a name="p1036431939165622"></a>The socket requiring for the connection is not of the <strong id="b553461237165622"><a name="b553461237165622"></a><a name="b553461237165622"></a>NETCONN_TCP</strong> type. </p>
</td>
</tr>
<tr id="row287312541165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1209160498165622"><a name="p1209160498165622"></a><a name="p1209160498165622"></a>EWOULDBLOCK </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p611384930165622"><a name="p611384930165622"></a><a name="p611384930165622"></a>Failure to receive events in non-blocking mode. </p>
</td>
</tr>
<tr id="row1477472830165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1625152205165622"><a name="p1625152205165622"></a><a name="p1625152205165622"></a>ENFILE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1718582839165622"><a name="p1718582839165622"></a><a name="p1718582839165622"></a>Failure to creat a new socket. </p>
</td>
</tr>
<tr id="row41128124165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2125901799165622"><a name="p2125901799165622"></a><a name="p2125901799165622"></a>ECONNABORTED </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p309617997165622"><a name="p309617997165622"></a><a name="p309617997165622"></a>Failure to receive the remote information. </p>
</td>
</tr>
<tr id="row1792146375165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p853386428165622"><a name="p853386428165622"></a><a name="p853386428165622"></a>ENOMEM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p737691553165622"><a name="p737691553165622"></a><a name="p737691553165622"></a>Memory copy exception. </p>
</td>
</tr>
</tbody>
</table>

## bind\(\)<a name="ga82199bcd81894331533a25f08e172480"></a>

```
int bind (int sockfd, const struct [sockaddr](sockaddr.md) * addr, [socklen_t](UTILS.md#ga531675af4e35aaa1cc9aeefa6cc2ccc4) addrlen )
```

 **Description:**

Binds a local protocol address to a socket. 

This function is called by the server. 

**Parameters:**

<a name="table713606971165622"></a>
<table><thead align="left"><tr id="row948838358165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p690785349165622"><a name="p690785349165622"></a><a name="p690785349165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p219007496165622"><a name="p219007496165622"></a><a name="p219007496165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1316989831165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sockfd</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the socket descriptor. </td>
</tr>
<tr id="row53601815165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">addr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the address to be bound to the socket. </td>
</tr>
<tr id="row556951803165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">addrlen</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the length of the address structure pointed to by <strong id="b810051443165622"><a name="b810051443165622"></a><a name="b810051443165622"></a>addr</strong>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails. 

<a name="table480351298165622"></a>
<table><thead align="left"><tr id="row1984523631165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2138772798165622"><a name="p2138772798165622"></a><a name="p2138772798165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p474147697165622"><a name="p474147697165622"></a><a name="p474147697165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row2132465564165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1908616449165622"><a name="p1908616449165622"></a><a name="p1908616449165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p219021308165622"><a name="p219021308165622"></a><a name="p219021308165622"></a>Invalid input parameter </p>
</td>
</tr>
</tbody>
</table>

## connect\(\)<a name="gacdfd99b6c59c833776412fbb0c539efb"></a>

```
int connect (int sockfd, const struct [sockaddr](sockaddr.md) * addr, [socklen_t](UTILS.md#ga531675af4e35aaa1cc9aeefa6cc2ccc4) addrlen )
```

 **Description:**

Connects a socket to the specified address. 

This function is for a connection request from the client and for TCP only. 

**Parameters:**

<a name="table1891159778165622"></a>
<table><thead align="left"><tr id="row1049791804165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2117154217165622"><a name="p2117154217165622"></a><a name="p2117154217165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1892509992165622"><a name="p1892509992165622"></a><a name="p1892509992165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row567282376165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sockfd</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the socket descriptor. </td>
</tr>
<tr id="row2006194440165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">addr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the address to be connected. </td>
</tr>
<tr id="row1910310406165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">addrlen</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the length of the address structure pointed to by <strong id="b298109556165622"><a name="b298109556165622"></a><a name="b298109556165622"></a>addr</strong>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails. 

<a name="table972270719165622"></a>
<table><thead align="left"><tr id="row1481619355165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1912289858165622"><a name="p1912289858165622"></a><a name="p1912289858165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1764810490165622"><a name="p1764810490165622"></a><a name="p1764810490165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1347093746165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1880658983165622"><a name="p1880658983165622"></a><a name="p1880658983165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p219449763165622"><a name="p219449763165622"></a><a name="p219449763165622"></a>Invalid input parameter </p>
</td>
</tr>
<tr id="row1304755980165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1069915862165622"><a name="p1069915862165622"></a><a name="p1069915862165622"></a>EBADF </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p482070342165622"><a name="p482070342165622"></a><a name="p482070342165622"></a>Invalid socket or socket status exception </p>
</td>
</tr>
<tr id="row1815504730165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p315071300165622"><a name="p315071300165622"></a><a name="p315071300165622"></a>EIO </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1771638473165622"><a name="p1771638473165622"></a><a name="p1771638473165622"></a>Incorrect connection type obtained based on the socket descriptor </p>
</td>
</tr>
<tr id="row551308974165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p610899078165622"><a name="p610899078165622"></a><a name="p610899078165622"></a>ECONNREFUSED </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1214517030165622"><a name="p1214517030165622"></a><a name="p1214517030165622"></a>Restart due to connection failure </p>
</td>
</tr>
<tr id="row1514043796165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1456164159165622"><a name="p1456164159165622"></a><a name="p1456164159165622"></a>ECONNABORTED </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p431417014165622"><a name="p431417014165622"></a><a name="p431417014165622"></a>Shut-down due to connection failure </p>
</td>
</tr>
</tbody>
</table>

## dn\_comp\(\)<a name="ga0438570faf515401bffa1a0d9c94a266"></a>

```
int dn_comp (const char * src, unsigned char * dst, int space, unsigned char ** dnptrs, unsigned char ** lastdnptr )
```

 **Description:**

Compresses a network domain name. 

To reduce the size of DNS messages, domain names in the messages are compressed. For details about the compression scheme, see RFC 1035.

**Parameters:**

<a name="table854829615165622"></a>
<table><thead align="left"><tr id="row682619064165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p488136935165622"><a name="p488136935165622"></a><a name="p488136935165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2111442261165622"><a name="p2111442261165622"></a><a name="p2111442261165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row471655969165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">src</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the domain name to be compressed. </td>
</tr>
<tr id="row1452731441165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">dst</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the compressed domain name. </td>
</tr>
<tr id="row1218558239165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">space</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the size of the compressed domain name. </td>
</tr>
<tr id="row1395516833165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">dnptrs</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to an array of pointers to previously compressed domain names. If the value is <strong id="b1819423883165622"><a name="b1819423883165622"></a><a name="b1819423883165622"></a>NULL</strong>, the current domain name will not be compressed. </td>
</tr>
<tr id="row148953177165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">lastdnptr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the last element of the array. If the value is <strong id="b1848648395165622"><a name="b1848648395165622"></a><a name="b1848648395165622"></a>NULL</strong>, the array is not updated. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the length of the compressed domain name if the operation is successful; returns  **-1**  otherwise. 

## dn\_expand\(\)<a name="ga91eb2055a64b28e4942a3a760d747243"></a>

```
int dn_expand (const unsigned char * base, const unsigned char * end, const unsigned char * src, char * dest, int space )
```

 **Description:**

Expands a compressed domain name to a full domain name. 

The compressed domain name is contained in a query or reply message.

**Parameters:**

<a name="table902919260165622"></a>
<table><thead align="left"><tr id="row546995947165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p679153524165622"><a name="p679153524165622"></a><a name="p679153524165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p968080850165622"><a name="p968080850165622"></a><a name="p968080850165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1223486683165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">base</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the start of the DNS message body. </td>
</tr>
<tr id="row349820507165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">end</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the end of the DNS message body. </td>
</tr>
<tr id="row1384028048165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">src</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the compressed domain name. </td>
</tr>
<tr id="row506948768165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">dest</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the expanded domain name. </td>
</tr>
<tr id="row2144182237165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">space</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the memory size of the <strong id="b1947532315165622"><a name="b1947532315165622"></a><a name="b1947532315165622"></a>dest</strong> address. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the length of the compressed domain name if the operation is successful; returns  **-1**  otherwise. 

## ether\_aton\(\)<a name="gaab4c5b65c36fc0ea96a017daabc3770a"></a>

```
struct [ether_addr](ether_addr.md)* ether_aton (const char * x)
```

 **Description:**

Converts a standard 48-bit Ethernet host address in the colon hexadecimal notation into binary data in network byte order. 

**Parameters:**

<a name="table48786352165622"></a>
<table><thead align="left"><tr id="row499836244165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1033734121165622"><a name="p1033734121165622"></a><a name="p1033734121165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1418408145165622"><a name="p1418408145165622"></a><a name="p1418408145165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row445836520165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the host address to be converted. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the binary data if the operation is successful; returns  **0**  otherwise. 

## ether\_aton\_r\(\)<a name="gac0954821754bace30f674e61bb9f4e5f"></a>

```
struct [ether_addr](ether_addr.md)* ether_aton_r (const char * x, struct [ether_addr](ether_addr.md) * p_a )
```

 **Description:**

Converts a standard 48-bit Ethernet host address in the colon hexadecimal notation into binary data in network byte order. This function is reentrant. 

This function is used in multitasking scenarios. 

**Parameters:**

<a name="table1904155982165622"></a>
<table><thead align="left"><tr id="row1891579244165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1107539930165622"><a name="p1107539930165622"></a><a name="p1107539930165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1944755905165622"><a name="p1944755905165622"></a><a name="p1944755905165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1337566103165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the host address to be converted. </td>
</tr>
<tr id="row1721890829165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">p_a</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the temporary buffer during conversion. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the binary data represented by  **[ether\_addr](ether_addr.md)**  if the operation is successful; returns  **0**  otherwise. 

## ether\_ntoa\(\)<a name="ga07e34e6ee9e272c4799780915d11677c"></a>

```
char* ether_ntoa (const struct [ether_addr](ether_addr.md) * p_a)
```

 **Description:**

Converts binary data in network byte order into a standard 48-bit Ethernet host address in the colon hexadecimal notation. 

**Parameters:**

<a name="table1649462210165622"></a>
<table><thead align="left"><tr id="row1635666694165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p585309851165622"><a name="p585309851165622"></a><a name="p585309851165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1268357689165622"><a name="p1268357689165622"></a><a name="p1268357689165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1217314927165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">p_a</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the binary data to be converted. </td>
</tr>
</tbody>
</table>

**Attention:**

Different from glibc \(for example, 1:2:3:4:5:f\), 0 is prefixed and letters are capitalized \(for example, 01:02:03:04:05:0F\). 

**Returns:**

Returns the host address if the operation is successful; returns  **0**  otherwise. 

## ether\_ntoa\_r\(\)<a name="ga245e21de8e82756712a5182c2674c2ad"></a>

```
char* ether_ntoa_r (const struct [ether_addr](ether_addr.md) * p_a, char * x )
```

 **Description:**

Converts binary data in network byte order into a standard 48-bit Ethernet host address in the colon hexadecimal notation. This function is reentrant. 

This function is used in multitasking scenarios. 

**Parameters:**

<a name="table1521297917165622"></a>
<table><thead align="left"><tr id="row379313284165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p54629457165622"><a name="p54629457165622"></a><a name="p54629457165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1838947496165622"><a name="p1838947496165622"></a><a name="p1838947496165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row376822111165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">p_a</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the binary data to be converted. </td>
</tr>
<tr id="row766172647165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">x</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the temporary buffer during conversion. </td>
</tr>
</tbody>
</table>

**Attention:**

Different from glibc \(for example, 1:2:3:4:5:f\), 0 is prefixed and letters are capitalized \(for example, 01:02:03:04:05:0F\). 

**Returns:**

Returns the host address if the operation is successful; returns  **0**  otherwise. 

## freeifaddrs\(\)<a name="gabfdd6ca5469fe73ed88ba94bf8db57cc"></a>

```
void freeifaddrs (struct [ifaddrs](ifaddrs.md) * ifp)
```

 **Description:**

Frees the network interface information obtained by  **getifaddrs**. 

**Parameters:**

<a name="table1645097997165622"></a>
<table><thead align="left"><tr id="row1614552133165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1582504236165622"><a name="p1582504236165622"></a><a name="p1582504236165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p228913070165622"><a name="p228913070165622"></a><a name="p228913070165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1017365380165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">ifp</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the network interface information to be freed. </td>
</tr>
</tbody>
</table>

## getpeername\(\)<a name="ga13d77555ad4ed62dfef0ce32dd16755c"></a>

```
int getpeername (int fd, struct [sockaddr](sockaddr.md) *restrict addr, [socklen_t](UTILS.md#ga531675af4e35aaa1cc9aeefa6cc2ccc4) *restrict len )
```

 **Description:**

Retrieves the peer address of the specified socket. 

**Parameters:**

<a name="table2130888681165622"></a>
<table><thead align="left"><tr id="row1756316704165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1146956765165622"><a name="p1146956765165622"></a><a name="p1146956765165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p167719177165622"><a name="p167719177165622"></a><a name="p167719177165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1346021165165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">fd</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the socket descriptor. </td>
</tr>
<tr id="row1263033415165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">addr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the address to be retrieved. </td>
</tr>
<tr id="row1885006891165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">len</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the length of the address pointed to by <strong id="b494598373165622"><a name="b494598373165622"></a><a name="b494598373165622"></a>addr</strong>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails. 

<a name="table281927066165622"></a>
<table><thead align="left"><tr id="row63489491165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1644766537165622"><a name="p1644766537165622"></a><a name="p1644766537165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1521000187165622"><a name="p1521000187165622"></a><a name="p1521000187165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row688669502165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1078341194165622"><a name="p1078341194165622"></a><a name="p1078341194165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p951065180165622"><a name="p951065180165622"></a><a name="p951065180165622"></a>Invalid input parameter </p>
</td>
</tr>
<tr id="row2098261493165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1330989091165622"><a name="p1330989091165622"></a><a name="p1330989091165622"></a>EBADF </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1602752490165622"><a name="p1602752490165622"></a><a name="p1602752490165622"></a>Invalid socket or socket status exception </p>
</td>
</tr>
<tr id="row1470941087165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1992213301165622"><a name="p1992213301165622"></a><a name="p1992213301165622"></a>ENOMEM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1840044802165622"><a name="p1840044802165622"></a><a name="p1840044802165622"></a>Memory copy exception </p>
</td>
</tr>
</tbody>
</table>

## getprotobyname\(\)<a name="ga83ac8a97dd9d895cda658af3aa46fd55"></a>

```
struct [protoent](protoent.md)* getprotobyname (const char * name)
```

 **Description:**

Retrieves the information about a specified protocol. 

**Parameters:**

<a name="table39463221165622"></a>
<table><thead align="left"><tr id="row1859283741165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p44200625165622"><a name="p44200625165622"></a><a name="p44200625165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p779136554165622"><a name="p779136554165622"></a><a name="p779136554165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2054881981165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">name</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the protocol name. </td>
</tr>
</tbody>
</table>

**Attention:**

The  **/etc/protocols**  configuration file is not supported. Only the following built-in protocols are supported: ip/icmp/igmp/ggp/ipencap/st/tcp/egp/pup/udp/hmp/xns-idp/rdp/iso-tp4/xtp/ ddp/idpr-cmtp/ipv6/ipv6-route/ipv6-frag/idrp/rsvp/gre/esp/ah/skip/ipv6-icmp/ ipv6-nonxt/ipv6-opts/rspf/vmtp/ospf/ipip/encap/pim/raw \(This protocol does not have the  **aliases**  attribute, that is,  **aliases**  is empty.\) 

**Returns:**

Returns the pointer to the protocol information if the operation is successful; returns  **NULL**  otherwise. 

## getprotobynumber\(\)<a name="gac01697dc4a5b8e434522220913bd46ea"></a>

```
struct [protoent](protoent.md)* getprotobynumber (int num)
```

 **Description:**

Retrieves the information about a protocol with the specified number. 

**Parameters:**

<a name="table2028819964165622"></a>
<table><thead align="left"><tr id="row1559141268165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1353902789165622"><a name="p1353902789165622"></a><a name="p1353902789165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1158673789165622"><a name="p1158673789165622"></a><a name="p1158673789165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2056968096165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">num</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the protocol number. </td>
</tr>
</tbody>
</table>

**Attention:**

The  **/etc/protocols**  configuration file is not supported. Only the following built-in protocols are supported: ip/icmp/igmp/ggp/ipencap/st/tcp/egp/pup/udp/hmp/xns-idp/rdp/iso-tp4/xtp/ ddp/idpr-cmtp/ipv6/ipv6-route/ipv6-frag/idrp/rsvp/gre/esp/ah/skip/ipv6-icmp/ ipv6-nonxt/ipv6-opts/rspf/vmtp/ospf/ipip/encap/pim/raw \(This protocol does not have the  **aliases**  attribute, that is,  **aliases**  is empty.\) 

**Returns:**

Returns the pointer to the protocol information if the operation is successful; returns  **NULL**  otherwise. 

## getprotoent\(\)<a name="gaca0da70657afbc3e723990bb229deec3"></a>

```
struct [protoent](protoent.md)* getprotoent (void )
```

 **Description:**

Retrieves the current protocol information. 

**Attention:**

The  **/etc/protocols**  configuration file is not supported. Only the following built-in protocols are supported: ip/icmp/igmp/ggp/ipencap/st/tcp/egp/pup/udp/hmp/xns-idp/rdp/iso-tp4/xtp/ ddp/idpr-cmtp/ipv6/ipv6-route/ipv6-frag/idrp/rsvp/gre/esp/ah/skip/ipv6-icmp/ ipv6-nonxt/ipv6-opts/rspf/vmtp/ospf/ipip/encap/pim/raw \(This protocol does not have the  **aliases**  attribute, that is,  **aliases**  is empty.\) 

**Returns:**

Returns the pointer to the protocol information if the operation is successful; returns  **NULL**  otherwise. 

## getsockname\(\)<a name="ga62577da7dba23abb9c99cf5c2800ab24"></a>

```
int getsockname (int fd, struct [sockaddr](sockaddr.md) *restrict addr, [socklen_t](UTILS.md#ga531675af4e35aaa1cc9aeefa6cc2ccc4) *restrict len )
```

 **Description:**

Retrieves the local address of the specified socket. 

**Parameters:**

<a name="table1144522689165622"></a>
<table><thead align="left"><tr id="row733198546165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p298845216165622"><a name="p298845216165622"></a><a name="p298845216165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1909870511165622"><a name="p1909870511165622"></a><a name="p1909870511165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1285873736165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">fd</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the socket descriptor. </td>
</tr>
<tr id="row690858441165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">addr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the address to be retrieved. </td>
</tr>
<tr id="row1449137277165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">len</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the length of the address pointed to by <strong id="b2108757610165622"><a name="b2108757610165622"></a><a name="b2108757610165622"></a>addr</strong>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails. 

<a name="table251514008165622"></a>
<table><thead align="left"><tr id="row1037770948165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1812535047165622"><a name="p1812535047165622"></a><a name="p1812535047165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p503578794165622"><a name="p503578794165622"></a><a name="p503578794165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row281601191165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p414860373165622"><a name="p414860373165622"></a><a name="p414860373165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1363911209165622"><a name="p1363911209165622"></a><a name="p1363911209165622"></a>Invalid input parameter </p>
</td>
</tr>
<tr id="row1892059359165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p300746155165622"><a name="p300746155165622"></a><a name="p300746155165622"></a>EBADF </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1078805533165622"><a name="p1078805533165622"></a><a name="p1078805533165622"></a>Invalid socket or socket status exception </p>
</td>
</tr>
<tr id="row1588481232165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1884668429165622"><a name="p1884668429165622"></a><a name="p1884668429165622"></a>ENOMEM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p155863714165622"><a name="p155863714165622"></a><a name="p155863714165622"></a>Memory copy exception </p>
</td>
</tr>
</tbody>
</table>

## getsockopt\(\)<a name="gacfcf672e255123afb75ed4d326257073"></a>

```
int getsockopt (int fd, int level, int optname, void *__restrict optval, [socklen_t](UTILS.md#ga531675af4e35aaa1cc9aeefa6cc2ccc4) *__restrict optlen )
```

 **Description:**

Retrieves the socket options. 

**Parameters:**

<a name="table1529165015165622"></a>
<table><thead align="left"><tr id="row833016483165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p460079961165622"><a name="p460079961165622"></a><a name="p460079961165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1371325929165622"><a name="p1371325929165622"></a><a name="p1371325929165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row143645405165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">fd</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the socket descriptor. </td>
</tr>
<tr id="row319755470165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">level</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the protocol level at which the option resides. Only <a href="NET.md#ga92d045f6ee2f343d6b28830a9fec082e">SOL_SOCKET</a> is supported. </td>
</tr>
<tr id="row66086432165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">optname</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the socket options to be retrieved, which has the following values: <a name="ul2032249469165622"></a><a name="ul2032249469165622"></a><ul id="ul2032249469165622"><li> <strong id="b1721014161165622"><a name="b1721014161165622"></a><a name="b1721014161165622"></a>SO_BROADCAST</strong>: permits sending and receiving broadcast messages. </li><li> <strong id="b515076003165622"><a name="b515076003165622"></a><a name="b515076003165622"></a>SO_RCVTIMEO</strong>: defines the data receiving timeout interval. </li><li> <strong id="b93682515165622"><a name="b93682515165622"></a><a name="b93682515165622"></a>SO_RCVBUF</strong>: defines the size of the socket receiving buffer, in bytes. </li><li> <strong id="b2002197963165622"><a name="b2002197963165622"></a><a name="b2002197963165622"></a>SO_TYPE</strong>: defines the socket type. </li><li> <strong id="b1612514122165622"><a name="b1612514122165622"></a><a name="b1612514122165622"></a>SO_DONTROUTE</strong>: prohibits messages from being sent via a gateway. </li><li> <strong id="b1122436175165622"><a name="b1122436175165622"></a><a name="b1122436175165622"></a>SO_BINDTODEVICE</strong>: binds this socket to a particular device. </li></ul>
 </td>
</tr>
<tr id="row1216926511165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">optval</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the option data. </td>
</tr>
<tr id="row1955164994165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">optlen</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the size of the buffer pointed to by <strong id="b2089337381165622"><a name="b2089337381165622"></a><a name="b2089337381165622"></a>optval</strong>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails. 

<a name="table1716134352165622"></a>
<table><thead align="left"><tr id="row902885948165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2005552319165622"><a name="p2005552319165622"></a><a name="p2005552319165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p92032999165622"><a name="p92032999165622"></a><a name="p92032999165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row141793314165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2131978241165622"><a name="p2131978241165622"></a><a name="p2131978241165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p457710475165622"><a name="p457710475165622"></a><a name="p457710475165622"></a>Small <strong id="b107127836165622"><a name="b107127836165622"></a><a name="b107127836165622"></a>optlen</strong> </p>
</td>
</tr>
<tr id="row127690050165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2073984146165622"><a name="p2073984146165622"></a><a name="p2073984146165622"></a>EBADF </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p708583302165622"><a name="p708583302165622"></a><a name="p708583302165622"></a>Invalid socket or socket status exception </p>
</td>
</tr>
<tr id="row250541438165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p441199416165622"><a name="p441199416165622"></a><a name="p441199416165622"></a>EFAULT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1406737641165622"><a name="p1406737641165622"></a><a name="p1406737641165622"></a>The input parameter is a null pointer. </p>
</td>
</tr>
<tr id="row1803081290165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p687492786165622"><a name="p687492786165622"></a><a name="p687492786165622"></a>ENOBUFS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1484376458165622"><a name="p1484376458165622"></a><a name="p1484376458165622"></a>Retrieved length exception </p>
</td>
</tr>
<tr id="row1595490586165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p595995488165622"><a name="p595995488165622"></a><a name="p595995488165622"></a>ENOMEM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1776642023165622"><a name="p1776642023165622"></a><a name="p1776642023165622"></a>Memory copy exception </p>
</td>
</tr>
</tbody>
</table>

## herror\(\)<a name="gaa68de2578d4e0849f82d70b2f5b9af70"></a>

```
void herror (const char * msg)
```

 **Description:**

Prints error information. 

**Parameters:**

<a name="table808668396165622"></a>
<table><thead align="left"><tr id="row686093819165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p558755381165622"><a name="p558755381165622"></a><a name="p558755381165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2037451933165622"><a name="p2037451933165622"></a><a name="p2037451933165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row457772135165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">msg</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the string to be printed together with the error information. This parameter can be null. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails. 

<a name="table1160477253165622"></a>
<table><thead align="left"><tr id="row1309022599165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2130085162165622"><a name="p2130085162165622"></a><a name="p2130085162165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1307237148165622"><a name="p1307237148165622"></a><a name="p1307237148165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1577675924165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1013216160165622"><a name="p1013216160165622"></a><a name="p1013216160165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p22408198165622"><a name="p22408198165622"></a><a name="p22408198165622"></a>Incorrect symbols or parameters </p>
</td>
</tr>
<tr id="row185418846165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1624831766165622"><a name="p1624831766165622"></a><a name="p1624831766165622"></a>EOVERFLOW </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1387936412165622"><a name="p1387936412165622"></a><a name="p1387936412165622"></a>Long item for printing </p>
</td>
</tr>
</tbody>
</table>

## hstrerror\(\)<a name="gac1752c48d9cf2ff87e29f29df6caa585"></a>

```
const char* hstrerror (int ecode)
```

 **Description:**

Retrieves error information associated with the specified error number. 

**Parameters:**

<a name="table305768475165622"></a>
<table><thead align="left"><tr id="row940280891165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p968800214165622"><a name="p968800214165622"></a><a name="p968800214165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p978887876165622"><a name="p978887876165622"></a><a name="p978887876165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1664007572165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">ecode</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the error number. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the string representing the error information. 

## htonl\(\)<a name="gac7eed08cd3b67f42bf56063157c8fd55"></a>

```
uint32_t htonl (uint32_t n)
```

 **Description:**

Converts an integer from the host byte order to the network byte order. 

**Parameters:**

<a name="table674819814165622"></a>
<table><thead align="left"><tr id="row272424996165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1767546246165622"><a name="p1767546246165622"></a><a name="p1767546246165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p787844752165622"><a name="p787844752165622"></a><a name="p787844752165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row869775108165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">n</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the integer in host byte order. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the original data if the system is in big-endian mode; returns the converted data otherwise. 

## htons\(\)<a name="gaabce0f8d453c3380e5b8a3d4947eb48c"></a>

```
uint16_t htons (uint16_t n)
```

 **Description:**

Converts a 16-bit integer from the host byte order to the network byte order. 

**Parameters:**

<a name="table82065631165622"></a>
<table><thead align="left"><tr id="row309037540165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1267344672165622"><a name="p1267344672165622"></a><a name="p1267344672165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1610200226165622"><a name="p1610200226165622"></a><a name="p1610200226165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1595497530165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">n</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the integer in host byte order. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the original data if the system is in big-endian mode; returns the converted data otherwise. 

## if\_freenameindex\(\)<a name="ga7fe55c04ac2116fa501338fdcb279cc9"></a>

```
void if_freenameindex (struct [if_nameindex](if_nameindex.md) * idx)
```

 **Description:**

Frees the network adapter information obtained by  [if\_nameindex](if_nameindex.md). 

**Parameters:**

<a name="table2029892003165622"></a>
<table><thead align="left"><tr id="row619094219165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2113623901165622"><a name="p2113623901165622"></a><a name="p2113623901165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p357539435165622"><a name="p357539435165622"></a><a name="p357539435165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row732309131165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">idx</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the network adapter to be freed. </td>
</tr>
</tbody>
</table>

## inet\_addr\(\)<a name="ga617651ec952a1f4c9cbddbf78f4b2e2e"></a>

```
[in_addr_t](NET.md#ga98b38134a62f24554da0ffcabde8062c) inet_addr (const char * p)
```

 **Description:**

Converts a string from the IPv4 numbers-and-dots notation to the binary data in network byte order. 

**Parameters:**

<a name="table655591876165622"></a>
<table><thead align="left"><tr id="row575180888165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1506292217165622"><a name="p1506292217165622"></a><a name="p1506292217165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1368185496165622"><a name="p1368185496165622"></a><a name="p1368185496165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1266245029165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">p</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the string to be converted. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the converted data if the operation is successful; returns  **-1**  otherwise. 

## inet\_aton\(\)<a name="ga26ee8e8e3949699a9c0e02ece272d370"></a>

```
int inet_aton (const char * s0, struct [in_addr](in_addr.md) * dest )
```

 **Description:**

Converts an IP address from the string format to the 32-bit binary format in network byte order. 

**Parameters:**

<a name="table64129353165622"></a>
<table><thead align="left"><tr id="row180441540165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1237119965165622"><a name="p1237119965165622"></a><a name="p1237119965165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1859408708165622"><a name="p1859408708165622"></a><a name="p1859408708165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row969209096165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">s0</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the IP address to be converted. </td>
</tr>
<tr id="row1669041925165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">dest</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the structure for conversion. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **1**  if the operation is successful; returns  **0**  otherwise. 

## inet\_lnaof\(\)<a name="ga1facb1380b7657ca9c72fb2633b60e3b"></a>

```
[in_addr_t](NET.md#ga98b38134a62f24554da0ffcabde8062c) inet_lnaof (struct [in_addr](in_addr.md) in)
```

 **Description:**

Converts an IP address into a host ID in host byte order without network bits. 

**Parameters:**

<a name="table1809648285165622"></a>
<table><thead align="left"><tr id="row948309329165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1941159200165622"><a name="p1941159200165622"></a><a name="p1941159200165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p638605084165622"><a name="p638605084165622"></a><a name="p638605084165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1668234989165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">in</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the network address structure. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the converted host address. 

## inet\_makeaddr\(\)<a name="gab28732d1d740597f53fb65a09d97800c"></a>

```
struct [in_addr](in_addr.md) inet_makeaddr ([in_addr_t](NET.md#ga98b38134a62f24554da0ffcabde8062c) n, [in_addr_t](NET.md#ga98b38134a62f24554da0ffcabde8062c) h )
```

 **Description:**

Converts the network number and host address to the network address. 

**Parameters:**

<a name="table458480416165622"></a>
<table><thead align="left"><tr id="row1332643454165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1706607080165622"><a name="p1706607080165622"></a><a name="p1706607080165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1750728300165622"><a name="p1750728300165622"></a><a name="p1750728300165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1099747719165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">n</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the network number. </td>
</tr>
<tr id="row1819647406165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">h</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the host address. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the converted network address. 

## inet\_netof\(\)<a name="ga3a96aa4e6abe8e6959ea63fe338174dd"></a>

```
[in_addr_t](NET.md#ga98b38134a62f24554da0ffcabde8062c) inet_netof (struct [in_addr](in_addr.md) in)
```

 **Description:**

Extracts the network number from the  **[in\_addr](in_addr.md)**  structure and converts it to the host byte order. 

**Parameters:**

<a name="table1743831957165622"></a>
<table><thead align="left"><tr id="row956977218165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p545085777165622"><a name="p545085777165622"></a><a name="p545085777165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1274854793165622"><a name="p1274854793165622"></a><a name="p1274854793165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1955463862165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">in</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the network address structure. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the converted network number. 

## inet\_network\(\)<a name="ga6f478437c4810fce89cf0e77d94181f8"></a>

```
[in_addr_t](NET.md#ga98b38134a62f24554da0ffcabde8062c) inet_network (const char * p)
```

 **Description:**

Converts a string from the IPv4 numbers-and-dots notation to the binary data in host byte order. 

**Parameters:**

<a name="table1144464170165622"></a>
<table><thead align="left"><tr id="row1394149536165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p602802702165622"><a name="p602802702165622"></a><a name="p602802702165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p432970873165622"><a name="p432970873165622"></a><a name="p432970873165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1798902276165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">p</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the string to be converted. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the converted data if the operation is successful; returns  **-1**  otherwise. 

## inet\_ntoa\(\)<a name="ga08b9fff487151e004d9862cbf34a51ad"></a>

```
char* inet_ntoa (struct [in_addr](in_addr.md) in)
```

 **Description:**

Converts a network address to a string in dotted-decimal format. 

**Parameters:**

<a name="table512175740165622"></a>
<table><thead align="left"><tr id="row1966618585165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1579544147165622"><a name="p1579544147165622"></a><a name="p1579544147165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p428001567165622"><a name="p428001567165622"></a><a name="p428001567165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1335521107165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">in</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the network address to be converted. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the string. 

## inet\_ntop\(\)<a name="gae9a2182ca3255f16723adeea14665b55"></a>

```
const char* inet_ntop (int af, const void *restrict a0, char *restrict s, [socklen_t](UTILS.md#ga531675af4e35aaa1cc9aeefa6cc2ccc4) l )
```

 **Description:**

Converts a network address in the specified address family to a string. 

**Parameters:**

<a name="table1973006420165622"></a>
<table><thead align="left"><tr id="row2059591852165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p287552184165622"><a name="p287552184165622"></a><a name="p287552184165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1054167812165622"><a name="p1054167812165622"></a><a name="p1054167812165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row230806906165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">af</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the address family. Currently, only <strong id="b446780516165622"><a name="b446780516165622"></a><a name="b446780516165622"></a>AF_INET</strong> and <strong id="b1219132459165622"><a name="b1219132459165622"></a><a name="b1219132459165622"></a>AF_INET6</strong> are supported. </td>
</tr>
<tr id="row1827726306165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">a0</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the data to be converted. </td>
</tr>
<tr id="row1481232381165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">s</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the string to be converted. </td>
</tr>
<tr id="row1757252165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">l</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the size of the string to be converted. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the converted string if the operation is successful; returns  **NULL**  and sets  **errno**  to a value in the following table if the operation fails. 

<a name="table828387338165622"></a>
<table><thead align="left"><tr id="row1129338970165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p874026143165622"><a name="p874026143165622"></a><a name="p874026143165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p642972488165622"><a name="p642972488165622"></a><a name="p642972488165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row257670399165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p421551101165622"><a name="p421551101165622"></a><a name="p421551101165622"></a>ENOSPC </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1043868518165622"><a name="p1043868518165622"></a><a name="p1043868518165622"></a>Insufficient space for conversion </p>
</td>
</tr>
<tr id="row686729703165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2139632768165622"><a name="p2139632768165622"></a><a name="p2139632768165622"></a>EAFNOSUPPORT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1178108948165622"><a name="p1178108948165622"></a><a name="p1178108948165622"></a>Unsupported address family </p>
</td>
</tr>
</tbody>
</table>

## inet\_pton\(\)<a name="ga3f6e2b2dae98a409d77c6e3b0cebc04b"></a>

```
int inet_pton (int af, const char *__restrict s, void *__restrict a0 )
```

 **Description:**

Converts a string to a network address in the specified address family. 

**Parameters:**

<a name="table749047634165622"></a>
<table><thead align="left"><tr id="row1408014768165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1146690434165622"><a name="p1146690434165622"></a><a name="p1146690434165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p298432394165622"><a name="p298432394165622"></a><a name="p298432394165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row469365474165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">af</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the address family. Currently, only <strong id="b759148085165622"><a name="b759148085165622"></a><a name="b759148085165622"></a>AF_INET</strong> and <strong id="b1580211350165622"><a name="b1580211350165622"></a><a name="b1580211350165622"></a>AF_INET6</strong> are supported. </td>
</tr>
<tr id="row1391679015165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">s</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the string to be converted. </td>
</tr>
<tr id="row935204758165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">a0</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the converted data. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **1**  if the operation is successful; returns  **0**  if the input address family is invalid; returns  **-1**  if the operation fails. The error codes are set as follows: 

<a name="table1386791624165622"></a>
<table><thead align="left"><tr id="row684274755165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p662293644165622"><a name="p662293644165622"></a><a name="p662293644165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1831819451165622"><a name="p1831819451165622"></a><a name="p1831819451165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row925000646165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2080269608165622"><a name="p2080269608165622"></a><a name="p2080269608165622"></a>EAFNOSUPPORT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1126694401165622"><a name="p1126694401165622"></a><a name="p1126694401165622"></a>Unsupported address family </p>
</td>
</tr>
</tbody>
</table>

## listen\(\)<a name="ga5989c21d05cb17caba26cef496a7beea"></a>

```
int listen (int sockfd, int backlog )
```

 **Description:**

Listens for network connection requests on a socket. 

This function is for TCP only. 

**Parameters:**

<a name="table1106984666165622"></a>
<table><thead align="left"><tr id="row1470292682165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1952137596165622"><a name="p1952137596165622"></a><a name="p1952137596165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p130578091165622"><a name="p130578091165622"></a><a name="p130578091165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1225118291165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sockfd</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the socket descriptor. </td>
</tr>
<tr id="row1055985685165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">backlog</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the maximum length of the queue to accept incoming connection requests. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails. 

<a name="table845096291165622"></a>
<table><thead align="left"><tr id="row1328380750165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1660607020165622"><a name="p1660607020165622"></a><a name="p1660607020165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1757504246165622"><a name="p1757504246165622"></a><a name="p1757504246165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1739564279165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p798769123165622"><a name="p798769123165622"></a><a name="p798769123165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1250063258165622"><a name="p1250063258165622"></a><a name="p1250063258165622"></a>Invalid input parameter </p>
</td>
</tr>
<tr id="row1431847897165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1397938403165622"><a name="p1397938403165622"></a><a name="p1397938403165622"></a>EBADF </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p405871069165622"><a name="p405871069165622"></a><a name="p405871069165622"></a>Invalid socket or socket status exception </p>
</td>
</tr>
<tr id="row1965531542165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1417830901165622"><a name="p1417830901165622"></a><a name="p1417830901165622"></a>EIO </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1691371930165622"><a name="p1691371930165622"></a><a name="p1691371930165622"></a>Incorrect connection type obtained based on the socket descriptor </p>
</td>
</tr>
</tbody>
</table>

## ntohl\(\)<a name="gae68530d41f32dfef707f20b2bbaa5a44"></a>

```
uint32_t ntohl (uint32_t n)
```

 **Description:**

Converts an integer from the network byte order to the host byte order. 

**Parameters:**

<a name="table1707953700165622"></a>
<table><thead align="left"><tr id="row118127734165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1220934945165622"><a name="p1220934945165622"></a><a name="p1220934945165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1668780679165622"><a name="p1668780679165622"></a><a name="p1668780679165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row960812215165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">n</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the integer in network byte order. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the original data if the system is in big-endian mode; returns the converted data otherwise. 

## ntohs\(\)<a name="gaf8c87af507c59bd8fef112e5e35fe537"></a>

```
uint16_t ntohs (uint16_t n)
```

 **Description:**

Converts a 16-bit integer from the network byte order to the host byte order. 

**Parameters:**

<a name="table828881769165622"></a>
<table><thead align="left"><tr id="row2039091607165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2120111782165622"><a name="p2120111782165622"></a><a name="p2120111782165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p740145571165622"><a name="p740145571165622"></a><a name="p740145571165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1953894945165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">n</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the integer in network byte order. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the original data if the system is in big-endian mode; returns the converted data otherwise. 

## recv\(\)<a name="ga5d049263cd0e3206b93530e68dfd7403"></a>

```
ssize_t recv (int fd, void * buf, size_t len, int flags )
```

 **Description:**

Receives data from another socket. 

**Parameters:**

<a name="table1573107242165622"></a>
<table><thead align="left"><tr id="row1841235141165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p345295023165622"><a name="p345295023165622"></a><a name="p345295023165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p509460010165622"><a name="p509460010165622"></a><a name="p509460010165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1549073178165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">fd</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the socket descriptor. </td>
</tr>
<tr id="row1183136372165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">buf</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to a buffer for storing the data to be received. </td>
</tr>
<tr id="row1199342100165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">len</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the length of the buffer pointed to by <strong id="b230610131165622"><a name="b230610131165622"></a><a name="b230610131165622"></a>buf</strong>. </td>
</tr>
<tr id="row353029961165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">flags</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the socket flags. This parameter has the following values: <a name="ul1680986920165622"></a><a name="ul1680986920165622"></a><ul id="ul1680986920165622"><li> <strong id="b423701280165622"><a name="b423701280165622"></a><a name="b423701280165622"></a>MSG_DONTWAIT</strong>: enables the non-blocking operation. </li><li> <strong id="b1095347516165622"><a name="b1095347516165622"></a><a name="b1095347516165622"></a>MSG_MORE</strong>: indicates that more messages are to be sent. </li><li> <strong id="b1098097566165622"><a name="b1098097566165622"></a><a name="b1098097566165622"></a>MSG_NOSIGNAL</strong>: indicates that no signals are generated. </li></ul>
 </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the length of the received data if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails. 

<a name="table105871736165622"></a>
<table><thead align="left"><tr id="row1232403581165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p246853519165622"><a name="p246853519165622"></a><a name="p246853519165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p111092589165622"><a name="p111092589165622"></a><a name="p111092589165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row527312108165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p742417357165622"><a name="p742417357165622"></a><a name="p742417357165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p82509318165622"><a name="p82509318165622"></a><a name="p82509318165622"></a>Invalid input parameter </p>
</td>
</tr>
<tr id="row1024437809165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p787191016165622"><a name="p787191016165622"></a><a name="p787191016165622"></a>EBADF </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2001986240165622"><a name="p2001986240165622"></a><a name="p2001986240165622"></a>Invalid socket or socket status exception </p>
</td>
</tr>
<tr id="row1032874587165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1607751675165622"><a name="p1607751675165622"></a><a name="p1607751675165622"></a>ENOMEM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2000403461165622"><a name="p2000403461165622"></a><a name="p2000403461165622"></a>Memory copy exception </p>
</td>
</tr>
<tr id="row91964381165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2110461587165622"><a name="p2110461587165622"></a><a name="p2110461587165622"></a>EOPNOTSUPP </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1202253269165622"><a name="p1202253269165622"></a><a name="p1202253269165622"></a>Unsupported message type </p>
</td>
</tr>
<tr id="row1820110479165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1810465412165622"><a name="p1810465412165622"></a><a name="p1810465412165622"></a>ENOTCONN </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p51820452165622"><a name="p51820452165622"></a><a name="p51820452165622"></a>Socket not connected </p>
</td>
</tr>
<tr id="row2094908833165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p356285592165622"><a name="p356285592165622"></a><a name="p356285592165622"></a>EWOULDBLOCK </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1832393060165622"><a name="p1832393060165622"></a><a name="p1832393060165622"></a>Blocking operation </p>
</td>
</tr>
<tr id="row1836960663165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p898948971165622"><a name="p898948971165622"></a><a name="p898948971165622"></a>ENOTCONN </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1455183655165622"><a name="p1455183655165622"></a><a name="p1455183655165622"></a>Connection closed </p>
</td>
</tr>
</tbody>
</table>

## recvfrom\(\)<a name="ga3089d3ee59e26bd4def3ef870175540e"></a>

```
ssize_t recvfrom (int fd, void *__restrict buf, size_t len, int flags, struct [sockaddr](sockaddr.md) *__restrict addr, [socklen_t](UTILS.md#ga531675af4e35aaa1cc9aeefa6cc2ccc4) *__restrict alen )
```

 **Description:**

Receives data from a specified socket. 

**Parameters:**

<a name="table1591707460165622"></a>
<table><thead align="left"><tr id="row1371880415165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1141842162165622"><a name="p1141842162165622"></a><a name="p1141842162165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1570664092165622"><a name="p1570664092165622"></a><a name="p1570664092165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row114971941165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">fd</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the socket descriptor. </td>
</tr>
<tr id="row253858184165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">buf</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to a buffer for storing the data to be received. </td>
</tr>
<tr id="row191626809165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">len</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the length of the buffer pointed to by <strong id="b2123609839165622"><a name="b2123609839165622"></a><a name="b2123609839165622"></a>buf</strong>. </td>
</tr>
<tr id="row1548360207165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">flags</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the socket flags. This parameter has the following values: <a name="ul1650604583165622"></a><a name="ul1650604583165622"></a><ul id="ul1650604583165622"><li> <strong id="b479761070165622"><a name="b479761070165622"></a><a name="b479761070165622"></a>MSG_DONTWAIT</strong>: enables the non-blocking operation. </li><li> <strong id="b1090411261165622"><a name="b1090411261165622"></a><a name="b1090411261165622"></a>MSG_MORE</strong>: indicates that more messages are to be sent. </li><li> <strong id="b414836294165622"><a name="b414836294165622"></a><a name="b414836294165622"></a>MSG_NOSIGNAL</strong>: indicates that no signals are generated. </li></ul>
 </td>
</tr>
<tr id="row378162222165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">addr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the source address. </td>
</tr>
<tr id="row1862991872165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">alen</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the size of the source address. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the length of the received data if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails. 

<a name="table1180320775165622"></a>
<table><thead align="left"><tr id="row1940524361165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p631502453165622"><a name="p631502453165622"></a><a name="p631502453165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p161978665165622"><a name="p161978665165622"></a><a name="p161978665165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row213634366165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1677831741165622"><a name="p1677831741165622"></a><a name="p1677831741165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1891260132165622"><a name="p1891260132165622"></a><a name="p1891260132165622"></a>Invalid input parameter </p>
</td>
</tr>
<tr id="row1342201323165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1849293100165622"><a name="p1849293100165622"></a><a name="p1849293100165622"></a>EBADF </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1189534131165622"><a name="p1189534131165622"></a><a name="p1189534131165622"></a>Invalid socket or socket status exception </p>
</td>
</tr>
<tr id="row1807570820165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p710353396165622"><a name="p710353396165622"></a><a name="p710353396165622"></a>ENOMEM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1229598048165622"><a name="p1229598048165622"></a><a name="p1229598048165622"></a>Memory copy exception </p>
</td>
</tr>
<tr id="row1333837629165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1081980861165622"><a name="p1081980861165622"></a><a name="p1081980861165622"></a>EOPNOTSUPP </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p583884455165622"><a name="p583884455165622"></a><a name="p583884455165622"></a>Unsupported message type </p>
</td>
</tr>
<tr id="row413368873165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p349600727165622"><a name="p349600727165622"></a><a name="p349600727165622"></a>ENOTCONN </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1952333869165622"><a name="p1952333869165622"></a><a name="p1952333869165622"></a>Socket not connected </p>
</td>
</tr>
<tr id="row1956777932165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1651717426165622"><a name="p1651717426165622"></a><a name="p1651717426165622"></a>ENOTCONN </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1872875155165622"><a name="p1872875155165622"></a><a name="p1872875155165622"></a>Connection closed </p>
</td>
</tr>
</tbody>
</table>

## recvmsg\(\)<a name="gaaba92f19a31c01b93e3391671a8b3dd5"></a>

```
ssize_t recvmsg (int fd, struct msghdr * msg, int flags )
```

 **Description:**

Receives data from a specified socket. 

**Parameters:**

<a name="table1781962163165622"></a>
<table><thead align="left"><tr id="row590888288165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1670095187165622"><a name="p1670095187165622"></a><a name="p1670095187165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p842726812165622"><a name="p842726812165622"></a><a name="p842726812165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1631380035165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">fd</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the socket descriptor. </td>
</tr>
<tr id="row19962885165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">msg</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the address to receive the message header. </td>
</tr>
<tr id="row89605981165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">flags</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the socket flags. This parameter has the following values: <a name="ul1426120192165622"></a><a name="ul1426120192165622"></a><ul id="ul1426120192165622"><li> <strong id="b419336057165622"><a name="b419336057165622"></a><a name="b419336057165622"></a>MSG_DONTWAIT</strong>: enables the non-blocking operation. </li><li> <strong id="b1953301670165622"><a name="b1953301670165622"></a><a name="b1953301670165622"></a>MSG_MORE</strong>: indicates that more messages are to be sent. </li><li> <strong id="b818195709165622"><a name="b818195709165622"></a><a name="b818195709165622"></a>MSG_NOSIGNAL</strong>: indicates that no signals are generated. </li></ul>
 </td>
</tr>
</tbody>
</table>

**Attention:**

This function does not allow sending ancillary data. Currently, the length of the array defined by  **msg\_iov**  can only be  **1**. 

**Returns:**

Returns the length of the received data if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails. 

<a name="table390929306165622"></a>
<table><thead align="left"><tr id="row1809873565165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p318448542165622"><a name="p318448542165622"></a><a name="p318448542165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p603033742165622"><a name="p603033742165622"></a><a name="p603033742165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1704037170165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1326848850165622"><a name="p1326848850165622"></a><a name="p1326848850165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1503640610165622"><a name="p1503640610165622"></a><a name="p1503640610165622"></a>Invalid input parameter </p>
</td>
</tr>
<tr id="row43853162165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1703631730165622"><a name="p1703631730165622"></a><a name="p1703631730165622"></a>EBADF </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p36699432165622"><a name="p36699432165622"></a><a name="p36699432165622"></a>Invalid socket or socket status exception </p>
</td>
</tr>
<tr id="row535787986165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1168060636165622"><a name="p1168060636165622"></a><a name="p1168060636165622"></a>EDESTADDRREQ </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p89042471165622"><a name="p89042471165622"></a><a name="p89042471165622"></a>Invalid connection </p>
</td>
</tr>
<tr id="row2050790562165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p51472572165622"><a name="p51472572165622"></a><a name="p51472572165622"></a>ENOMEM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2047052868165622"><a name="p2047052868165622"></a><a name="p2047052868165622"></a>Memory copy exception </p>
</td>
</tr>
<tr id="row838415440165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p846302753165622"><a name="p846302753165622"></a><a name="p846302753165622"></a>EIO </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p614878406165622"><a name="p614878406165622"></a><a name="p614878406165622"></a>Incorrect connection type obtained based on the socket descriptor </p>
</td>
</tr>
</tbody>
</table>

## send\(\)<a name="ga4053f5c8e26fd490ef54e2a0abf5c89f"></a>

```
ssize_t send (int fd, const void * buf, size_t len, int flags )
```

 **Description:**

Sends data to another socket. 

**Parameters:**

<a name="table1408968051165622"></a>
<table><thead align="left"><tr id="row1400539434165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1210687333165622"><a name="p1210687333165622"></a><a name="p1210687333165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p345652771165622"><a name="p345652771165622"></a><a name="p345652771165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row820701846165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">fd</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the socket descriptor. </td>
</tr>
<tr id="row1095263211165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">buf</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to a buffer for storing the data to be sent. </td>
</tr>
<tr id="row1083040570165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">len</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the length of the buffer pointed to by <strong id="b1756827134165622"><a name="b1756827134165622"></a><a name="b1756827134165622"></a>buf</strong>. </td>
</tr>
<tr id="row677832878165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">flags</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the socket flags. This parameter has the following values: <a name="ul537310962165622"></a><a name="ul537310962165622"></a><ul id="ul537310962165622"><li> <strong id="b79933264165622"><a name="b79933264165622"></a><a name="b79933264165622"></a>MSG_DONTWAIT</strong>: enables the non-blocking operation. </li><li> <strong id="b1275903006165622"><a name="b1275903006165622"></a><a name="b1275903006165622"></a>MSG_MORE</strong>: indicates that more messages are to be sent. </li><li> <strong id="b273008003165622"><a name="b273008003165622"></a><a name="b273008003165622"></a>MSG_NOSIGNAL</strong>: indicates that no signals are generated. </li></ul>
 </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the length of the sent data if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails. 

<a name="table379550084165622"></a>
<table><thead align="left"><tr id="row1414488780165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1793988935165622"><a name="p1793988935165622"></a><a name="p1793988935165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p664856944165622"><a name="p664856944165622"></a><a name="p664856944165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row548964657165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1256238635165622"><a name="p1256238635165622"></a><a name="p1256238635165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1465561434165622"><a name="p1465561434165622"></a><a name="p1465561434165622"></a>Invalid input parameter </p>
</td>
</tr>
<tr id="row1520055148165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1361247644165622"><a name="p1361247644165622"></a><a name="p1361247644165622"></a>EBADF </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p904275937165622"><a name="p904275937165622"></a><a name="p904275937165622"></a>Invalid socket or socket status exception </p>
</td>
</tr>
<tr id="row1094977589165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p773766144165622"><a name="p773766144165622"></a><a name="p773766144165622"></a>EDESTADDRREQ </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2064231005165622"><a name="p2064231005165622"></a><a name="p2064231005165622"></a>Invalid connection </p>
</td>
</tr>
<tr id="row476717747165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1382514615165622"><a name="p1382514615165622"></a><a name="p1382514615165622"></a>ENOMEM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1877878712165622"><a name="p1877878712165622"></a><a name="p1877878712165622"></a>Memory copy exception </p>
</td>
</tr>
<tr id="row330047752165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1124395749165622"><a name="p1124395749165622"></a><a name="p1124395749165622"></a>EOPNOTSUPP </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1332342402165622"><a name="p1332342402165622"></a><a name="p1332342402165622"></a>Unsupported message type </p>
</td>
</tr>
<tr id="row1763316909165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1876198389165622"><a name="p1876198389165622"></a><a name="p1876198389165622"></a>ENOTCONN </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p719380237165622"><a name="p719380237165622"></a><a name="p719380237165622"></a>Socket not connected </p>
</td>
</tr>
<tr id="row1410775326165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1114901699165622"><a name="p1114901699165622"></a><a name="p1114901699165622"></a>EIO </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p683768375165622"><a name="p683768375165622"></a><a name="p683768375165622"></a>Incorrect connection type obtained based on the socket descriptor </p>
</td>
</tr>
</tbody>
</table>

## sendmsg\(\)<a name="ga70c97d3a1eab72cba4461d66a1778570"></a>

```
ssize_t sendmsg (int fd, const struct msghdr * msg, int flags )
```

 **Description:**

Sends data to another socket. 

**Parameters:**

<a name="table2003642991165622"></a>
<table><thead align="left"><tr id="row281738608165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1182719182165622"><a name="p1182719182165622"></a><a name="p1182719182165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1231193220165622"><a name="p1231193220165622"></a><a name="p1231193220165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row202569633165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">fd</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the socket descriptor. </td>
</tr>
<tr id="row919606313165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">msg</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the address of the message header to be sent. </td>
</tr>
<tr id="row1975688829165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">flags</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the socket flags. This parameter has the following values: <a name="ul101920041165622"></a><a name="ul101920041165622"></a><ul id="ul101920041165622"><li> <strong id="b2105690175165622"><a name="b2105690175165622"></a><a name="b2105690175165622"></a>MSG_DONTWAIT</strong>: enables the non-blocking operation. </li><li> <strong id="b818682883165622"><a name="b818682883165622"></a><a name="b818682883165622"></a>MSG_MORE</strong>: indicates that more messages are to be sent. </li><li> <strong id="b1867441760165622"><a name="b1867441760165622"></a><a name="b1867441760165622"></a>MSG_NOSIGNAL</strong>: indicates that no signals are generated. </li></ul>
 </td>
</tr>
</tbody>
</table>

**Attention:**

This function does not support ancillary data. 

**Returns:**

Returns the length of the sent data if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails. 

<a name="table1871876849165622"></a>
<table><thead align="left"><tr id="row899654001165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1117318248165622"><a name="p1117318248165622"></a><a name="p1117318248165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p633000629165622"><a name="p633000629165622"></a><a name="p633000629165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row232863306165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2054391433165622"><a name="p2054391433165622"></a><a name="p2054391433165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1708502002165622"><a name="p1708502002165622"></a><a name="p1708502002165622"></a>Invalid input parameter </p>
</td>
</tr>
<tr id="row731996934165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1979806940165622"><a name="p1979806940165622"></a><a name="p1979806940165622"></a>EBADF </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1414211956165622"><a name="p1414211956165622"></a><a name="p1414211956165622"></a>Invalid socket or socket status exception </p>
</td>
</tr>
<tr id="row1084088514165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1273821964165622"><a name="p1273821964165622"></a><a name="p1273821964165622"></a>EDESTADDRREQ </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p143688215165622"><a name="p143688215165622"></a><a name="p143688215165622"></a>Invalid connection </p>
</td>
</tr>
<tr id="row8793281165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p613400313165622"><a name="p613400313165622"></a><a name="p613400313165622"></a>ENOMEM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1089111164165622"><a name="p1089111164165622"></a><a name="p1089111164165622"></a>Memory copy exception </p>
</td>
</tr>
<tr id="row1802342347165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p840857179165622"><a name="p840857179165622"></a><a name="p840857179165622"></a>EIO </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1209311990165622"><a name="p1209311990165622"></a><a name="p1209311990165622"></a>Incorrect connection type obtained based on the socket descriptor </p>
</td>
</tr>
<tr id="row1078403412165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1173740951165622"><a name="p1173740951165622"></a><a name="p1173740951165622"></a>EOPNOTSUPP </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p236097347165622"><a name="p236097347165622"></a><a name="p236097347165622"></a>Unsupported message type </p>
</td>
</tr>
</tbody>
</table>

## sendto\(\)<a name="ga2587b27d2c6014c6b568a974655f41c5"></a>

```
ssize_t sendto (int fd, const void * buf, size_t len, int flags, const struct [sockaddr](sockaddr.md) * addr, [socklen_t](UTILS.md#ga531675af4e35aaa1cc9aeefa6cc2ccc4) alen )
```

 **Description:**

Sends data to another socket. 

**Parameters:**

<a name="table1243270958165622"></a>
<table><thead align="left"><tr id="row758233510165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p549228094165622"><a name="p549228094165622"></a><a name="p549228094165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p678954953165622"><a name="p678954953165622"></a><a name="p678954953165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row793051133165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">fd</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the socket descriptor. </td>
</tr>
<tr id="row459321373165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">buf</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to a buffer for storing the data to be sent. </td>
</tr>
<tr id="row1925332016165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">len</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the length of the buffer pointed to by <strong id="b960027812165622"><a name="b960027812165622"></a><a name="b960027812165622"></a>buf</strong>. </td>
</tr>
<tr id="row2087477625165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">flags</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the socket flags. This parameter has the following values: <a name="ul739403842165622"></a><a name="ul739403842165622"></a><ul id="ul739403842165622"><li> <strong id="b1278103513165622"><a name="b1278103513165622"></a><a name="b1278103513165622"></a>MSG_DONTWAIT</strong>: enables the non-blocking operation. </li><li> <strong id="b1212772948165622"><a name="b1212772948165622"></a><a name="b1212772948165622"></a>MSG_MORE</strong>: indicates that more messages are to be sent. </li><li> <strong id="b901823708165622"><a name="b901823708165622"></a><a name="b901823708165622"></a>MSG_NOSIGNAL</strong>: indicates that no signals are generated. </li></ul>
 </td>
</tr>
<tr id="row653127444165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">addr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the destination network address. </td>
</tr>
<tr id="row65483771165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">alen</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the length of the destination network address. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the length of the sent data if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails. 

<a name="table2049650266165622"></a>
<table><thead align="left"><tr id="row1432610859165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p477127052165622"><a name="p477127052165622"></a><a name="p477127052165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p688609903165622"><a name="p688609903165622"></a><a name="p688609903165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row954404538165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1010941563165622"><a name="p1010941563165622"></a><a name="p1010941563165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1852133363165622"><a name="p1852133363165622"></a><a name="p1852133363165622"></a>Invalid input parameter </p>
</td>
</tr>
<tr id="row1586568296165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p161291741165622"><a name="p161291741165622"></a><a name="p161291741165622"></a>EBADF </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1742709178165622"><a name="p1742709178165622"></a><a name="p1742709178165622"></a>Invalid socket or socket status exception </p>
</td>
</tr>
<tr id="row1852734839165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1799687877165622"><a name="p1799687877165622"></a><a name="p1799687877165622"></a>EDESTADDRREQ </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p86833858165622"><a name="p86833858165622"></a><a name="p86833858165622"></a>Invalid connection </p>
</td>
</tr>
<tr id="row565358630165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2063733055165622"><a name="p2063733055165622"></a><a name="p2063733055165622"></a>ENOMEM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p658963748165622"><a name="p658963748165622"></a><a name="p658963748165622"></a>Memory copy exception </p>
</td>
</tr>
<tr id="row157862091165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1439707401165622"><a name="p1439707401165622"></a><a name="p1439707401165622"></a>EOPNOTSUPP </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1564323627165622"><a name="p1564323627165622"></a><a name="p1564323627165622"></a>Unsupported message type </p>
</td>
</tr>
<tr id="row269040438165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2067341612165622"><a name="p2067341612165622"></a><a name="p2067341612165622"></a>ENOTCONN </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p10340116165622"><a name="p10340116165622"></a><a name="p10340116165622"></a>Socket not connected </p>
</td>
</tr>
<tr id="row1585441086165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1332599748165622"><a name="p1332599748165622"></a><a name="p1332599748165622"></a>EIO </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p818080822165622"><a name="p818080822165622"></a><a name="p818080822165622"></a>Incorrect connection type obtained based on the socket descriptor </p>
</td>
</tr>
</tbody>
</table>

## setprotoent\(\)<a name="ga6a806414e4ae5bffb09e3a1d25d8db75"></a>

```
void setprotoent (int stayopen)
```

 **Description:**

Opens a connection to the database and sets the next entry to the first entry. 

**Parameters:**

<a name="table235604112165622"></a>
<table><thead align="left"><tr id="row1519813343165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1927872724165622"><a name="p1927872724165622"></a><a name="p1927872724165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2112918924165622"><a name="p2112918924165622"></a><a name="p2112918924165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1587291476165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">stayopen</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Reserved for interface compatibility (not used currently). </td>
</tr>
</tbody>
</table>

**Attention:**

The  **stayopen**  parameter does not take effect. It is equivalent to nonzero for  [getprotoent](NET.md#gaca0da70657afbc3e723990bb229deec3)  and zero for  [getprotobyname](NET.md#ga83ac8a97dd9d895cda658af3aa46fd55)  and  **getprotobynumbmer**. 

## setsockopt\(\)<a name="ga81983de50d79d797b2ac0f0d0f28953f"></a>

```
int setsockopt (int fd, int level, int optname, const void * optval, [socklen_t](UTILS.md#ga531675af4e35aaa1cc9aeefa6cc2ccc4) optlen )
```

 **Description:**

Sets the socket options. 

**Parameters:**

<a name="table203804243165622"></a>
<table><thead align="left"><tr id="row574168650165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1197932457165622"><a name="p1197932457165622"></a><a name="p1197932457165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p700231321165622"><a name="p700231321165622"></a><a name="p700231321165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1063310447165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">fd</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the socket descriptor. </td>
</tr>
<tr id="row822368270165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">level</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the protocol level at which the option resides. Only <a href="NET.md#ga92d045f6ee2f343d6b28830a9fec082e">SOL_SOCKET</a> is supported. </td>
</tr>
<tr id="row2074729006165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">optname</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the socket options to set, which has the following values: <a name="ul757791437165622"></a><a name="ul757791437165622"></a><ul id="ul757791437165622"><li> <strong id="b1486238932165622"><a name="b1486238932165622"></a><a name="b1486238932165622"></a>SO_BROADCAST</strong>: permits sending and receiving broadcast messages. </li><li> <strong id="b1631613195165622"><a name="b1631613195165622"></a><a name="b1631613195165622"></a>SO_RCVTIMEO</strong>: defines the data receiving timeout interval. </li><li> <strong id="b898087257165622"><a name="b898087257165622"></a><a name="b898087257165622"></a>SO_RCVBUF</strong>: defines the size of the socket receiving buffer, in bytes. </li><li> <strong id="b454748722165622"><a name="b454748722165622"></a><a name="b454748722165622"></a>SO_DONTROUTE</strong>: prohibits messages from being sent via a gateway. </li><li> <strong id="b312041715165622"><a name="b312041715165622"></a><a name="b312041715165622"></a>SO_BINDTODEVICE</strong>: binds this socket to a particular device. </li></ul>
 </td>
</tr>
<tr id="row689920274165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">optval</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the option data. </td>
</tr>
<tr id="row1780227255165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">optlen</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the size of the buffer pointed to by <strong id="b1382378791165622"><a name="b1382378791165622"></a><a name="b1382378791165622"></a>optval</strong>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails. 

<a name="table1934943906165622"></a>
<table><thead align="left"><tr id="row276789780165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1113912849165622"><a name="p1113912849165622"></a><a name="p1113912849165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1297926184165622"><a name="p1297926184165622"></a><a name="p1297926184165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1616064501165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p143922884165622"><a name="p143922884165622"></a><a name="p143922884165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p354057747165622"><a name="p354057747165622"></a><a name="p354057747165622"></a>Small <strong id="b1166842041165622"><a name="b1166842041165622"></a><a name="b1166842041165622"></a>optlen</strong> </p>
</td>
</tr>
<tr id="row285253428165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1556974223165622"><a name="p1556974223165622"></a><a name="p1556974223165622"></a>EBADF </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2000369002165622"><a name="p2000369002165622"></a><a name="p2000369002165622"></a>Invalid socket or socket status exception </p>
</td>
</tr>
<tr id="row924589301165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p445973337165622"><a name="p445973337165622"></a><a name="p445973337165622"></a>EFAULT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1933563188165622"><a name="p1933563188165622"></a><a name="p1933563188165622"></a>The input parameter is a null pointer. </p>
</td>
</tr>
<tr id="row605812311165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2041968899165622"><a name="p2041968899165622"></a><a name="p2041968899165622"></a>ENOBUFS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1405243771165622"><a name="p1405243771165622"></a><a name="p1405243771165622"></a>Retrieved length exception </p>
</td>
</tr>
<tr id="row1297491370165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p676034308165622"><a name="p676034308165622"></a><a name="p676034308165622"></a>ENOMEM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1798350200165622"><a name="p1798350200165622"></a><a name="p1798350200165622"></a>Memory copy exception </p>
</td>
</tr>
</tbody>
</table>

## shutdown\(\)<a name="ga402425b8e1ceab40ac38a949babcf1aa"></a>

```
int shutdown (int sockfd, int how )
```

 **Description:**

Shuts down a socket. 

**Parameters:**

<a name="table1556823402165622"></a>
<table><thead align="left"><tr id="row1648799676165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2029891292165622"><a name="p2029891292165622"></a><a name="p2029891292165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1934733194165622"><a name="p1934733194165622"></a><a name="p1934733194165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1377472331165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">sockfd</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the socket descriptor. </td>
</tr>
<tr id="row815546641165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">how</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates how to shut down the socket. You can disable either receptions by <a href="NET.md#gaf1c8cf84ac37451afaef3bde9976b6e1">SHUT_RD</a> or transmissions by <a href="NET.md#gaddb0a758e6fafdd89f5b7120f84738eb">SHUT_WR</a>, or both by <a href="NET.md#ga80c54d1399557c97a0c81a319d08e9db">SHUT_RDWR</a>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails. 

<a name="table829166080165622"></a>
<table><thead align="left"><tr id="row1459451330165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p89595715165622"><a name="p89595715165622"></a><a name="p89595715165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p109559593165622"><a name="p109559593165622"></a><a name="p109559593165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row2004565005165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1325921787165622"><a name="p1325921787165622"></a><a name="p1325921787165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p236618726165622"><a name="p236618726165622"></a><a name="p236618726165622"></a>Invalid input parameter </p>
</td>
</tr>
<tr id="row1812546720165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p608902846165622"><a name="p608902846165622"></a><a name="p608902846165622"></a>ENOTCONN </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p933516984165622"><a name="p933516984165622"></a><a name="p933516984165622"></a>Socket not connected </p>
</td>
</tr>
<tr id="row1190208395165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p722476900165622"><a name="p722476900165622"></a><a name="p722476900165622"></a>ENOMEM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p90027049165622"><a name="p90027049165622"></a><a name="p90027049165622"></a>Memory copy exception </p>
</td>
</tr>
<tr id="row374326188165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p488060995165622"><a name="p488060995165622"></a><a name="p488060995165622"></a>EIO </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1554890920165622"><a name="p1554890920165622"></a><a name="p1554890920165622"></a>Incorrect connection type obtained based on the socket descriptor </p>
</td>
</tr>
</tbody>
</table>

## socket\(\)<a name="gaf4e0711877c45a41168ac677b0670ccd"></a>

```
int socket (int domain, int type, int protocol )
```

 **Description:**

Creates a socket and returns its descriptor. 

**Parameters:**

<a name="table1040613760165622"></a>
<table><thead align="left"><tr id="row694308758165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2041014817165622"><a name="p2041014817165622"></a><a name="p2041014817165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1861436708165622"><a name="p1861436708165622"></a><a name="p1861436708165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row940634955165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">domain</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the socket family. </td>
</tr>
<tr id="row1154818220165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">type</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the socket type. </td>
</tr>
<tr id="row1623015202165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">protocol</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the socket protocol. </td>
</tr>
</tbody>
</table>

**Attention:**

The domain can only be  [AF\_INET](NET.md#ga9930604d0e32588eae76f43ca38e7826)  or  [AF\_INET6](NET.md#gaa03706b2738b9a58d4985dfbe99e1bac). The socket type can only be  [SOCK\_RAW](NET.md#ga346f84e37c42f88e91e7304c3d77fde8),  [SOCK\_DGRAM](NET.md#ga4db8b9a846c67404db0b6f014f9a9fdf), or  [SOCK\_STREAM](NET.md#ga249394484f9410a2e3f8eba24657feb9). 

**Returns:**

Returns the descriptor for the new socket if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails. 

<a name="table1002214375165622"></a>
<table><thead align="left"><tr id="row1260763115165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p475847806165622"><a name="p475847806165622"></a><a name="p475847806165622"></a>errno </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1812515391165622"><a name="p1812515391165622"></a><a name="p1812515391165622"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row334144067165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1167037144165622"><a name="p1167037144165622"></a><a name="p1167037144165622"></a>EAFNOSUPPORT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1648921027165622"><a name="p1648921027165622"></a><a name="p1648921027165622"></a>Invalid socket domain </p>
</td>
</tr>
<tr id="row108046408165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1225192772165622"><a name="p1225192772165622"></a><a name="p1225192772165622"></a>ESOCKTNOSUPPORT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p188172017165622"><a name="p188172017165622"></a><a name="p188172017165622"></a>Unsupported socket domain </p>
</td>
</tr>
<tr id="row956206314165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1231652465165622"><a name="p1231652465165622"></a><a name="p1231652465165622"></a>EPROTONOSUPPORT </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1663948098165622"><a name="p1663948098165622"></a><a name="p1663948098165622"></a>Unsupported protocol </p>
</td>
</tr>
<tr id="row1936045942165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p225964855165622"><a name="p225964855165622"></a><a name="p225964855165622"></a>EINVAL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1275124827165622"><a name="p1275124827165622"></a><a name="p1275124827165622"></a>Invalid input parameter </p>
</td>
</tr>
<tr id="row1827604775165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1821930028165622"><a name="p1821930028165622"></a><a name="p1821930028165622"></a>ENOBUFS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1199175373165622"><a name="p1199175373165622"></a><a name="p1199175373165622"></a>Connection setup error </p>
</td>
</tr>
<tr id="row2053318713165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1617109328165622"><a name="p1617109328165622"></a><a name="p1617109328165622"></a>ENFILE </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1606780966165622"><a name="p1606780966165622"></a><a name="p1606780966165622"></a>File table addition exception </p>
</td>
</tr>
</tbody>
</table>

