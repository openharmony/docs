# Glossary

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=563c3fe9cdad6b385a7bab92806c6884fd9ba7f9 translatedAt=2026-08-13T03:09:49.833Z pushedAt=2026-08-13T07:19:46.445Z -->

## D

### Domain Name System (DNS)

A system that translates human-readable domain names into machine-recognizable IP addresses, enabling the location and access of network resources.

### Default Network

The network that the system uses by default. It is determined by the system, regardless of whether an app specifies a network. Based on network availability, capabilities, priority, and other policies, the system selects the default network from Wi‑Fi, cellular data, Ethernet, and Bluetooth connections.

- If an app is not bound to a specific network, its requests are usually sent over the default network.

- The default network may change due to network switching, signal changes, or system policies.

- The default network is not necessarily the only available network; rather, it is the network currently preferred by the system.

## E

### Extensible Authentication Protocol (EAP)

An authentication framework used for network authentication that supports multiple authentication methods. In 802.1X networks, EAP provides a flexible authentication mechanism that can be used in Ethernet, Wi-Fi, and other networks, allowing developers to customize the EAP authentication process.

## H

### Hypertext Transfer Protocol (HTTP)

An application-layer protocol designed for distributed, collaborative, and hypermedia information systems.

### HTTPS

A security-enhanced communication protocol built upon HTTP, leveraging SSL/TLS encryption to ensure data transmission confidentiality, integrity, and identity authentication.

### Interceptor

A component used to intercept and modify HTTP requests and responses. It supports creating an interceptor chain and customizing a set of interceptors to modify network requests/responses as needed.

## M

### Multicast DNS (MDNS)

A protocol used to automatically discover and configure devices in a local area network (LAN).

### Multi-part Form

An object used to send HTTP multipart form data. It supports specifying the order in which keys in the form are sent, and is suitable for scenarios such as file upload.

## N

### Network Handle (NetHandle)

A network handle is an identifier used by the system to identify a specific network connection instance. An app can use the handle to query network capabilities, link attributes, routing status, and other information, or to bind traffic to a specified network.

- Used to uniquely identify an established or available network instance.

- Can be used for network query, network binding, and policy control.

- When no network is available, the `netId` of the network handle is `0`.

### Network Bearer Type (NetBearType)

The network bearer type indicates the category of the underlying access network, such as cellular network, Wi‑Fi, Ethernet, Bluetooth, or VPN, and is used to distinguish different types of network access methods.

### Network Probing

Network probing is a detection mechanism used by the system to evaluate network availability, connectivity, or Internet accessibility.

## S

### Secure Socket Layer (SSL)

A network security protocol that provides encryption and identity authentication for communications between clients (for example, browsers) and servers, ensuring the confidentiality, integrity, and reliability of transmitted data.

### System VPN

System VPN is the VPN connection and management capability provided by the system. Users can establish and manage VPN connections through system settings, enterprise configurations, or system interfaces. System VPN is usually deeply integrated with the system network stack and can uniformly manage connection status, routing, authentication, and policies.

## T

### Transmission Control Protocol (TCP)

A connection-oriented, reliable byte-stream transport layer protocol that supports reliable data delivery over IP networks.

### Transport Layer Security (TLS)

Transport Layer Security (TLS) is a protocol built on top of the transport-layer TCP protocol and serves the application layer. Its predecessor is SSL. It encrypts application-layer packets before handing them to TCP for transmission.

### Third-party VPN

A third-party VPN is a VPN app or service developed by a provider other than the operating system provider. It typically creates a virtual network interface and processes network traffic through the VPN capability provided by the system. Its specific protocols, functions, and security capabilities depend on the app implementation.

## U

### User Datagram Protocol (UDP)

A connectionless, lightweight transport layer protocol designed for real-time data transmission where reliability is secondary to low latency.

## V

### Virtual Private Network (VPN)

A technology used to establish a private network over a public network for encrypted communication.