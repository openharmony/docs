# socket.h<a name="EN-US_TOPIC_0000001055387988"></a>

-   [Overview](#section1503586833165629)
-   [Summary](#section1957135947165629)
-   [Data Structures](#nested-classes)
-   [Macros](#define-members)
-   [Functions](#func-members)

## **Overview**<a name="section1503586833165629"></a>

**Related Modules:**

[NET](net.md)

**Description:**

Declares functions and data structures related to network sockets. 

For example, you can use the functions to create and delete network sockets, listen to the network connection state, and send and receive network data.

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1957135947165629"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table1020781194165629"></a>
<table><thead align="left"><tr id="row2014687082165629"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p254906989165629"><a name="p254906989165629"></a><a name="p254906989165629"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1781854663165629"><a name="p1781854663165629"></a><a name="p1781854663165629"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1614197458165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1764784496165629"><a name="p1764784496165629"></a><a name="p1764784496165629"></a><a href="sockaddr.md">sockaddr</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2003208165165629"><a name="p2003208165165629"></a><a name="p2003208165165629"></a>Describes the socket address information. </p>
</td>
</tr>
</tbody>
</table>

## Macros<a name="define-members"></a>

<a name="table105851706165629"></a>
<table><thead align="left"><tr id="row454362656165629"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1263204307165629"><a name="p1263204307165629"></a><a name="p1263204307165629"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p366159514165629"><a name="p366159514165629"></a><a name="p366159514165629"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row59450898165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1534311984165629"><a name="p1534311984165629"></a><a name="p1534311984165629"></a><a href="net.md#gaf1c8cf84ac37451afaef3bde9976b6e1">SHUT_RD</a>   0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p233305149165629"><a name="p233305149165629"></a><a name="p233305149165629"></a>Disables reading data from a socket. </p>
</td>
</tr>
<tr id="row934987332165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1089059038165629"><a name="p1089059038165629"></a><a name="p1089059038165629"></a><a href="net.md#gaddb0a758e6fafdd89f5b7120f84738eb">SHUT_WR</a>   1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1798242683165629"><a name="p1798242683165629"></a><a name="p1798242683165629"></a>Disables writing data to a socket. </p>
</td>
</tr>
<tr id="row1502702480165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2141195903165629"><a name="p2141195903165629"></a><a name="p2141195903165629"></a><a href="net.md#ga80c54d1399557c97a0c81a319d08e9db">SHUT_RDWR</a>   2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p391027538165629"><a name="p391027538165629"></a><a name="p391027538165629"></a>Disables reading data from and writing data to a socket. </p>
</td>
</tr>
<tr id="row2009948416165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p826754183165629"><a name="p826754183165629"></a><a name="p826754183165629"></a><a href="net.md#ga3f5da0b5be27fe31ec7cc11bfa8d1a25">PF_INET</a>   2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p22541389165629"><a name="p22541389165629"></a><a name="p22541389165629"></a>Defines the IPv4 internet protocol family. </p>
</td>
</tr>
<tr id="row278298765165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p723866022165629"><a name="p723866022165629"></a><a name="p723866022165629"></a><a href="net.md#ga323f2649198fc7e64b19881869265618">PF_INET6</a>   10</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1483922764165629"><a name="p1483922764165629"></a><a name="p1483922764165629"></a>Defines the IPv6 internet protocol family. </p>
</td>
</tr>
<tr id="row1591640148165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p344749556165629"><a name="p344749556165629"></a><a name="p344749556165629"></a><a href="net.md#ga9930604d0e32588eae76f43ca38e7826">AF_INET</a>   <a href="net.md#ga3f5da0b5be27fe31ec7cc11bfa8d1a25">PF_INET</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1962556156165629"><a name="p1962556156165629"></a><a name="p1962556156165629"></a>Defines the IPv4 internet address. </p>
</td>
</tr>
<tr id="row471505396165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1660830259165629"><a name="p1660830259165629"></a><a name="p1660830259165629"></a><a href="net.md#gaa03706b2738b9a58d4985dfbe99e1bac">AF_INET6</a>   <a href="net.md#ga323f2649198fc7e64b19881869265618">PF_INET6</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p10069619165629"><a name="p10069619165629"></a><a name="p10069619165629"></a>Defines the IPv6 internet address. </p>
</td>
</tr>
<tr id="row1506941896165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p454932440165629"><a name="p454932440165629"></a><a name="p454932440165629"></a><a href="net.md#ga249394484f9410a2e3f8eba24657feb9">SOCK_STREAM</a>   1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1342037167165629"><a name="p1342037167165629"></a><a name="p1342037167165629"></a>Defines stream sockets. </p>
</td>
</tr>
<tr id="row1989011420165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1486641734165629"><a name="p1486641734165629"></a><a name="p1486641734165629"></a><a href="net.md#ga4db8b9a846c67404db0b6f014f9a9fdf">SOCK_DGRAM</a>   2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1470041553165629"><a name="p1470041553165629"></a><a name="p1470041553165629"></a>Defines datagram sockets. </p>
</td>
</tr>
<tr id="row1197846191165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1016943638165629"><a name="p1016943638165629"></a><a name="p1016943638165629"></a><a href="net.md#ga346f84e37c42f88e91e7304c3d77fde8">SOCK_RAW</a>   3</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p209971746165629"><a name="p209971746165629"></a><a name="p209971746165629"></a>Defines raw sockets. </p>
</td>
</tr>
<tr id="row1129662023165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1008088508165629"><a name="p1008088508165629"></a><a name="p1008088508165629"></a><a href="net.md#gab18d3d439e4a9c8d0f73e7166e8eb376">MSG_DONTWAIT</a>   0x0040</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p30173948165629"><a name="p30173948165629"></a><a name="p30173948165629"></a>Defines the message type of a non-blocking operation. </p>
</td>
</tr>
<tr id="row828440024165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p406899045165629"><a name="p406899045165629"></a><a name="p406899045165629"></a><a href="net.md#ga9f55d0e90dc8cc6b2287312435cdde48">MSG_NOSIGNAL</a>   0x4000</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p451773568165629"><a name="p451773568165629"></a><a name="p451773568165629"></a>Defines the message type that does not generate a signal. </p>
</td>
</tr>
<tr id="row353055122165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1703123041165629"><a name="p1703123041165629"></a><a name="p1703123041165629"></a><a href="net.md#ga7b7c7e5e523ff0fc8823e7bff7665ead">MSG_MORE</a>   0x8000</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p114389216165629"><a name="p114389216165629"></a><a name="p114389216165629"></a>Defines the message type that more data is to be transferred. </p>
</td>
</tr>
<tr id="row2035459305165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p815755624165629"><a name="p815755624165629"></a><a name="p815755624165629"></a><a href="net.md#ga8ab1e00e94a92737d3a4b407f7fa90f1">SO_TYPE</a>   3</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p713071809165629"><a name="p713071809165629"></a><a name="p713071809165629"></a>Obtains the socket type. </p>
</td>
</tr>
<tr id="row2100759020165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1633704060165629"><a name="p1633704060165629"></a><a name="p1633704060165629"></a><a href="net.md#ga4a6d9f7ea4bf046c50102c17ba1faf37">SO_DONTROUTE</a>   5</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p799377527165629"><a name="p799377527165629"></a><a name="p799377527165629"></a>Prohibits messages from being sent via a gateway. </p>
</td>
</tr>
<tr id="row1179219309165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p895103311165629"><a name="p895103311165629"></a><a name="p895103311165629"></a><a href="net.md#gad05e5d66b4608d73747c4a10b802a737">SO_BROADCAST</a>   6</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1243581468165629"><a name="p1243581468165629"></a><a name="p1243581468165629"></a>Enables sending broadcast messages. </p>
</td>
</tr>
<tr id="row1116478837165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p144303248165629"><a name="p144303248165629"></a><a name="p144303248165629"></a><a href="net.md#gaf618cbb85161ff3196d3bcdf7565ba64">SO_SNDBUF</a>   7</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p918808156165629"><a name="p918808156165629"></a><a name="p918808156165629"></a>Defines the size of the socket sending buffer, in bytes. </p>
</td>
</tr>
<tr id="row1286386314165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p995275968165629"><a name="p995275968165629"></a><a name="p995275968165629"></a><a href="net.md#ga0db12e960ac303030400d9fd95391b52">SO_RCVBUF</a>   8</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p589969526165629"><a name="p589969526165629"></a><a name="p589969526165629"></a>Defines the size of the socket receiving buffer, in bytes. </p>
</td>
</tr>
<tr id="row1137118542165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1687239094165629"><a name="p1687239094165629"></a><a name="p1687239094165629"></a><a href="net.md#gaf2d1ed6a34336a6f3df80fb518325846">SO_RCVTIMEO</a>   66</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1058221238165629"><a name="p1058221238165629"></a><a name="p1058221238165629"></a>Defines the data receiving timeout interval. </p>
</td>
</tr>
<tr id="row703186762165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p858704078165629"><a name="p858704078165629"></a><a name="p858704078165629"></a><a href="net.md#gab9d2f7ca5c94bd51cdab3e1913b66e2d">SO_SNDTIMEO</a>   67</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1974254555165629"><a name="p1974254555165629"></a><a name="p1974254555165629"></a>Defines the data sending timeout interval. </p>
</td>
</tr>
<tr id="row1435341921165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1731504009165629"><a name="p1731504009165629"></a><a name="p1731504009165629"></a><a href="net.md#gae0339480fb8088046e6038ee1baf3a61">SO_BINDTODEVICE</a>   25</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1345765593165629"><a name="p1345765593165629"></a><a name="p1345765593165629"></a>Binds the socket to a particular device. </p>
</td>
</tr>
<tr id="row30315408165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p153083979165629"><a name="p153083979165629"></a><a name="p153083979165629"></a><a href="net.md#ga92d045f6ee2f343d6b28830a9fec082e">SOL_SOCKET</a>   1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p423427465165629"><a name="p423427465165629"></a><a name="p423427465165629"></a>Defines the layers of a socket. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table1337587713165629"></a>
<table><thead align="left"><tr id="row576468556165629"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p935814032165629"><a name="p935814032165629"></a><a name="p935814032165629"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1100104957165629"><a name="p1100104957165629"></a><a name="p1100104957165629"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1665647645165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1445409544165629"><a name="p1445409544165629"></a><a name="p1445409544165629"></a><a href="net.md#gaf4e0711877c45a41168ac677b0670ccd">socket</a> (int domain, int type, int protocol)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1063553638165629"><a name="p1063553638165629"></a><a name="p1063553638165629"></a>int </p>
<p id="p937850216165629"><a name="p937850216165629"></a><a name="p937850216165629"></a>Creates a socket and returns its descriptor. </p>
</td>
</tr>
<tr id="row2124639596165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1002058039165629"><a name="p1002058039165629"></a><a name="p1002058039165629"></a><a href="net.md#ga402425b8e1ceab40ac38a949babcf1aa">shutdown</a> (int sockfd, int how)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1474529742165629"><a name="p1474529742165629"></a><a name="p1474529742165629"></a>int </p>
<p id="p1643708179165629"><a name="p1643708179165629"></a><a name="p1643708179165629"></a>Shuts down a socket. </p>
</td>
</tr>
<tr id="row1813623210165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1712365262165629"><a name="p1712365262165629"></a><a name="p1712365262165629"></a><a href="net.md#ga82199bcd81894331533a25f08e172480">bind</a> (int sockfd, const struct <a href="sockaddr.md">sockaddr</a> *addr, <a href="utils.md#ga531675af4e35aaa1cc9aeefa6cc2ccc4">socklen_t</a> addrlen)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p18456816165629"><a name="p18456816165629"></a><a name="p18456816165629"></a>int </p>
<p id="p1800238474165629"><a name="p1800238474165629"></a><a name="p1800238474165629"></a>Binds a local protocol address to a socket. </p>
</td>
</tr>
<tr id="row1410522042165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1849003116165629"><a name="p1849003116165629"></a><a name="p1849003116165629"></a><a href="net.md#gacdfd99b6c59c833776412fbb0c539efb">connect</a> (int sockfd, const struct <a href="sockaddr.md">sockaddr</a> *addr, <a href="utils.md#ga531675af4e35aaa1cc9aeefa6cc2ccc4">socklen_t</a> addrlen)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p645536082165629"><a name="p645536082165629"></a><a name="p645536082165629"></a>int </p>
<p id="p844745547165629"><a name="p844745547165629"></a><a name="p844745547165629"></a>Connects a socket to the specified address. </p>
</td>
</tr>
<tr id="row598780770165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1500170937165629"><a name="p1500170937165629"></a><a name="p1500170937165629"></a><a href="net.md#ga5989c21d05cb17caba26cef496a7beea">listen</a> (int sockfd, int backlog)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1291732359165629"><a name="p1291732359165629"></a><a name="p1291732359165629"></a>int </p>
<p id="p642447103165629"><a name="p642447103165629"></a><a name="p642447103165629"></a>Listens for network connection requests on a socket. </p>
</td>
</tr>
<tr id="row1656573441165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1540764878165629"><a name="p1540764878165629"></a><a name="p1540764878165629"></a><a href="net.md#ga0807af5ac9dfc2a63624e8c3e0ae95ef">accept</a> (int sockfd, struct <a href="sockaddr.md">sockaddr</a> *__restrict addr, <a href="utils.md#ga531675af4e35aaa1cc9aeefa6cc2ccc4">socklen_t</a> *__restrict addrlen)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1485208670165629"><a name="p1485208670165629"></a><a name="p1485208670165629"></a>int </p>
<p id="p381224679165629"><a name="p381224679165629"></a><a name="p381224679165629"></a>Accepts a connection request on a socket. </p>
</td>
</tr>
<tr id="row265621990165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1595014267165629"><a name="p1595014267165629"></a><a name="p1595014267165629"></a><a href="net.md#ga62577da7dba23abb9c99cf5c2800ab24">getsockname</a> (int fd, struct <a href="sockaddr.md">sockaddr</a> *restrict addr, <a href="utils.md#ga531675af4e35aaa1cc9aeefa6cc2ccc4">socklen_t</a> *restrict len)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p511952178165629"><a name="p511952178165629"></a><a name="p511952178165629"></a>int </p>
<p id="p1593666014165629"><a name="p1593666014165629"></a><a name="p1593666014165629"></a>Retrieves the local address of the specified socket. </p>
</td>
</tr>
<tr id="row1645406798165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1535968868165629"><a name="p1535968868165629"></a><a name="p1535968868165629"></a><a href="net.md#ga13d77555ad4ed62dfef0ce32dd16755c">getpeername</a> (int fd, struct <a href="sockaddr.md">sockaddr</a> *restrict addr, <a href="utils.md#ga531675af4e35aaa1cc9aeefa6cc2ccc4">socklen_t</a> *restrict len)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p964998739165629"><a name="p964998739165629"></a><a name="p964998739165629"></a>int </p>
<p id="p1131213906165629"><a name="p1131213906165629"></a><a name="p1131213906165629"></a>Retrieves the peer address of the specified socket. </p>
</td>
</tr>
<tr id="row1130136393165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p751157223165629"><a name="p751157223165629"></a><a name="p751157223165629"></a><a href="net.md#ga4053f5c8e26fd490ef54e2a0abf5c89f">send</a> (int fd, const void *buf, size_t len, int flags)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p583481579165629"><a name="p583481579165629"></a><a name="p583481579165629"></a>ssize_t </p>
<p id="p453530654165629"><a name="p453530654165629"></a><a name="p453530654165629"></a>Sends data to another socket. </p>
</td>
</tr>
<tr id="row2098976558165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2116968092165629"><a name="p2116968092165629"></a><a name="p2116968092165629"></a><a href="net.md#ga5d049263cd0e3206b93530e68dfd7403">recv</a> (int fd, void *buf, size_t len, int flags)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1115885779165629"><a name="p1115885779165629"></a><a name="p1115885779165629"></a>ssize_t </p>
<p id="p1036615159165629"><a name="p1036615159165629"></a><a name="p1036615159165629"></a>Receives data from another socket. </p>
</td>
</tr>
<tr id="row555392289165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1702068064165629"><a name="p1702068064165629"></a><a name="p1702068064165629"></a><a href="net.md#ga2587b27d2c6014c6b568a974655f41c5">sendto</a> (int fd, const void *buf, size_t len, int flags, const struct <a href="sockaddr.md">sockaddr</a> *addr, <a href="utils.md#ga531675af4e35aaa1cc9aeefa6cc2ccc4">socklen_t</a> alen)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1147891380165629"><a name="p1147891380165629"></a><a name="p1147891380165629"></a>ssize_t </p>
<p id="p1677893485165629"><a name="p1677893485165629"></a><a name="p1677893485165629"></a>Sends data to another socket. </p>
</td>
</tr>
<tr id="row1958626606165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1506673654165629"><a name="p1506673654165629"></a><a name="p1506673654165629"></a><a href="net.md#ga3089d3ee59e26bd4def3ef870175540e">recvfrom</a> (int fd, void *__restrict buf, size_t len, int flags, struct <a href="sockaddr.md">sockaddr</a> *__restrict addr, <a href="utils.md#ga531675af4e35aaa1cc9aeefa6cc2ccc4">socklen_t</a> *__restrict alen)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p883806108165629"><a name="p883806108165629"></a><a name="p883806108165629"></a>ssize_t </p>
<p id="p1233986670165629"><a name="p1233986670165629"></a><a name="p1233986670165629"></a>Receives data from a specified socket. </p>
</td>
</tr>
<tr id="row1084907740165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p8671127165629"><a name="p8671127165629"></a><a name="p8671127165629"></a><a href="net.md#ga70c97d3a1eab72cba4461d66a1778570">sendmsg</a> (int fd, const struct msghdr *msg, int flags)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p314860135165629"><a name="p314860135165629"></a><a name="p314860135165629"></a>ssize_t </p>
<p id="p1969749293165629"><a name="p1969749293165629"></a><a name="p1969749293165629"></a>Sends data to another socket. </p>
</td>
</tr>
<tr id="row2066297723165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1848421360165629"><a name="p1848421360165629"></a><a name="p1848421360165629"></a><a href="net.md#gaaba92f19a31c01b93e3391671a8b3dd5">recvmsg</a> (int fd, struct msghdr *msg, int flags)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p941450123165629"><a name="p941450123165629"></a><a name="p941450123165629"></a>ssize_t </p>
<p id="p659839840165629"><a name="p659839840165629"></a><a name="p659839840165629"></a>Receives data from a specified socket. </p>
</td>
</tr>
<tr id="row724644091165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1819669207165629"><a name="p1819669207165629"></a><a name="p1819669207165629"></a><a href="net.md#gacfcf672e255123afb75ed4d326257073">getsockopt</a> (int fd, int level, int optname, void *__restrict optval, <a href="utils.md#ga531675af4e35aaa1cc9aeefa6cc2ccc4">socklen_t</a> *__restrict optlen)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1000695076165629"><a name="p1000695076165629"></a><a name="p1000695076165629"></a>int </p>
<p id="p2095030666165629"><a name="p2095030666165629"></a><a name="p2095030666165629"></a>Retrieves the socket options. </p>
</td>
</tr>
<tr id="row1153367695165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1191889147165629"><a name="p1191889147165629"></a><a name="p1191889147165629"></a><a href="net.md#ga81983de50d79d797b2ac0f0d0f28953f">setsockopt</a> (int fd, int level, int optname, const void *optval, <a href="utils.md#ga531675af4e35aaa1cc9aeefa6cc2ccc4">socklen_t</a> optlen)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p796831388165629"><a name="p796831388165629"></a><a name="p796831388165629"></a>int </p>
<p id="p1850767193165629"><a name="p1850767193165629"></a><a name="p1850767193165629"></a>Sets the socket options. </p>
</td>
</tr>
</tbody>
</table>

