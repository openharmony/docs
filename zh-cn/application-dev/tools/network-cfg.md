# network-cfg工具

network-cfg是为开发人员提供用于设置网络相关参数的工具（其中"cfg"为"config"的缩写），例如给Wi-Fi设置代理等。

## 环境要求

<!--RP1-->

在使用本工具前，开发者需要先获取[hdc工具](../dfx/hdc.md)，执行hdc shell。

<!--RP1End-->

## network-cfg命令工具列表

| 命令 | 描述 |
| -------- | -------- |
| help | 帮助命令，显示network-cfg支持的命令信息。 |
| set | 设置网络相关参数命令。 |

## 帮助命令

```bash
# 显示帮助信息
network-cfg help
network-cfg -h
```

## 设置网络相关参数命令

- 显示set支持的命令信息

```bash
network-cfg set -h
```

- 设置或取消当前Wi-Fi代理。

```bash
network-cfg set http_proxy [ip:port]
```

> **说明：**
>
> - 当前Wi-Fi处于连接状态时，才可设置代理。
> - 端口号取值范围为[1, 65535]，不指定端口号或超出取值范围时则默认为8080。
> - 仅对当前连接的Wi-Fi生效，Wi-Fi切换后需重新设置。

示例：

```bash
# 给当前Wi-Fi设置代理：主机名为localhost，端口号为8080。
network-cfg set http_proxy 127.0.0.1:8080
# 给当前Wi-Fi设置代理：主机名为ip6-localhost，端口号为8080。
network-cfg set http_proxy [::1]
# 取消当前Wi-Fi代理。
network-cfg set http_proxy 0
```