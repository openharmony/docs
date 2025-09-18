# network-cfg

network-cfg is a tool (cfg is short for config) provided for developers to set network parameters, for example, setting a proxy for Wi-Fi.

## Environment Requirements

<!--RP1-->

Before using this tool, you must obtain [hdc](../dfx/hdc.md) and run the **hdc shell** command.

<!--RP1End-->

## network-cfg Commands

| Envelope command.| Description|
| -------- | -------- |
| help | Help command, which displays information about the commands supported by network-cfg.|
| set | Command for setting network parameters.|

## help

```bash
# Displays the help information.
network-cfg help
network-cfg -h
```

## Setting Network Parameters

- Display information about the set command.

```bash
network-cfg set -h
```

- Sets or cancels the current Wi-Fi proxy.

```bash
network-cfg set http_proxy [ip:port]
```

> **NOTE**
>
> - The proxy can be set only when the current Wi-Fi is connected.
> - The port number ranges from 1 to 65535. If no port number is specified or the port number is out of the range, the default port number 8080 is used.
> - This command takes effect only for the currently connected Wi-Fi. After Wi-Fi switching, you need to set the proxy again.

A **break** statement looks as follows:

```bash
# Set a proxy for the current Wi-Fi. The host name is localhost, and the port number is 8080.
network-cfg set http_proxy 127.0.0.1:8080
# Set a proxy for the current Wi-Fi. The host name is ip6-localhost, and the port number is 8080.
network-cfg set http_proxy [::1]
# Cancel the current Wi-Fi proxy.
network-cfg set http_proxy 0
```
