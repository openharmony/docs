# VPN Management (For System Applications Only)

## Overview

A virtual private network (VPN) is a dedicated network established on a public network. On a VPN, the connection between any two nodes does not have an end-to-end physical link required by the traditional private network. Instead, user data is transmitted over a logical link because a VPN is a logical network deployed over the network platform (such as the Internet) provided by the public network service provider.

> **NOTE**
> To maximize the application running efficiency, most API calls are called asynchronously in callback or promise mode. The following code examples use the promise mode. For details about the APIs, see [API Reference](../reference/apis-network-kit/js-apis-net-vpn-sys.md).

The following describes the development procedure specific to each application scenario.

## Available APIs

For the complete list of APIs and example code, see [API Reference](../reference/apis-network-kit/js-apis-net-vpn-sys.md).

| API                                                           | Description                                         |
| ----------------------------------------------------------------- | --------------------------------------------------- |
| setUp(config: VpnConfig, callback: AsyncCallback\<number\>): void | Establishes a VPN. This API uses an asynchronous callback to return the result.|
| protect(socketFd: number, callback: AsyncCallback\<void\>): void  | Enables VPN tunnel protection. This API uses an asynchronous callback to return the result.  |
| destroy(callback: AsyncCallback\<void\>): void                    | Destroys a VPN. This API uses an asynchronous callback to return the result.|

## Starting a VPN

1. Establish a VPN tunnel. The following uses the UDP tunnel as an example.
2. Enable protection for the UDP tunnel.
3. Establish a VPN.
4. Process data of the virtual network interface card (vNIC), such as reading or writing data.
5. Destroy the VPN.

This example shows how to develop an application using native C++ code. For details, see [Simple Native C++ Example (ArkTS) (API9)] (https://gitee.com/openharmony/codelabs/tree/master/NativeAPI/NativeTemplateDemo).

The sample application consists of two parts: JS code and C++ code.

## JS Code

The JS code is used to implement the service logic, such as creating a tunnel, establishing a VPN, enabling VPN protection, and destroying a VPN.

```js
import Want from '@ohos.app.ability.Want';
import VpnExtensionAbility from '@ohos.app.ability.VpnExtensionAbility';
import vpnExt from '@ohos.net.vpnExtension';
import hilog from '@ohos.hilog';
import common from '@ohos.app.ability.common';

// vpn_client is a portable .so file in C language, for example, import vpn_client from 'libvpn_client.so'.

import socket from '@ohos.net.socket';

const TAG: string = "[MyVpnExtAbility]";
let g_tunFd = -1;
let g_tunnelFd = -1;

export default class MyVpnExtAbility extends VpnExtensionAbility {
  private VpnConnection: vpnExt.VpnConnection = vpnExt.createVpnConnection(this.context);
  private vpnServerIp: string = '192.168.85.185';
  private tunIp: string = '10.0.0.8';
  private blockedAppName: string = 'com.example.testvpn';

  onCreate(want: Want) {
    console.info(TAG, `xdw onCreate, want: ${want.abilityName}`);
    // this.context.stopVpnExtensionAbility(want);
    this.VpnConnection = vpnExt.createVpnConnection(this.context);
    console.info("wmw createVpnConnection success")
    this.CreateTunnel();
    this.Protect();
    console.info("xdw step4");
  }

  onRequest(want: Want, startId: number) {
    console.info(TAG, `xdw onRequest, want: ${want.abilityName}`);
  }

  onConnect(want: Want) {
    console.info(TAG, `xdw onConnect, want: ${want.abilityName}`);
    // Return a ServiceExtImpl object, through which the client can communicate with the ServiceExtensionAbility.
    let abilityName  = want.parameters?.abilityName.toString();
    let bundleName = want.parameters?.bundleName.toString();
    return null;
  }

  onDisconnect(want: Want) {
    console.info(TAG, `xdw onDisconnect, want: ${want.abilityName}`);
  }

  onDestroy() {
    console.info(TAG, `xdw onDestroy`);
    this.Destroy();
  }

  Destroy() {
    hilog.info(0x0000, 'developTag', '%{public}s', 'vpn Destroy');
    // Disable the VPN.
    this.VpnConnection.destroy().then(() => {
      hilog.info(0x0000, 'developTag', '%{public}s', 'vpn Destroy Success');
    }).catch((err: Error) => {
      hilog.error(0x0000, 'developTag', 'vpn Destroy Failed: %{public}s', JSON.stringify(err) ?? '');
    })
  }

  CreateTunnel() {
    console.info("xdw step1")
    // Connect to the VPN server.
  }

  Protect() {
    console.info("xdw step2")
    hilog.info(0x0000, 'developTag', '%{public}s', 'vpn Protect');
    this.VpnConnection.protect(g_tunnelFd).then(() => {
      hilog.info(0x0000, 'developTag', '%{public}s', 'vpn Protect Success');
      this.SetupVpn();
    }).catch((err: Error) => {
      hilog.error(0x0000, 'developTag', 'vpn Protect Failed %{public}s', JSON.stringify(err) ?? '');
    })
  }

  SetupVpn() {
    console.info("xdw step3")
    hilog.info(0x0000, 'developTag', '%{public}s', 'vpn SetupVpn');

    class Address {
      address: string;
      family: number;

      constructor(address: string, family: number) {
        this.address = address;
        this.family = family;
      }
    }

    class AddressWithPrefix {
      address: Address;
      prefixLength: number;

      constructor(address: Address, prefixLength: number) {
        this.address = address;
        this.prefixLength = prefixLength;
      }
    }

    class Config {
      addresses: AddressWithPrefix[];
      dnsAddresses: string[];
      trustedApplications: string[];
      blockedApplications: string[];

      constructor(
        tunIp: string,
        blockedAppName: string
      ) {
        this.addresses = [
          new AddressWithPrefix(new Address(tunIp, 1), 24)
        ];
        this.dnsAddresses = ["114.114.114.114"];
        this.trustedApplications = [];
        this.blockedApplications = [];
      }
    }

    let config = new Config(this.tunIp, this.blockedAppName);

    try {
      this.VpnConnection.create(config);
    } catch (error) {
      hilog.error(0x0000, 'developTag', 'vpn setUp fail: %{public}s', JSON.stringify(error) ?? '');
    }
  }
}
```

## C++ Code

The C++ code is used for underlying service implementation, such as UDP tunnel client implementation and vNIC data read and write.

```c++
#include "napi/native_api.h"
#include "hilog/log.h"

#include <cstring>
#include <thread>
#include <js_native_api.h>
#include <js_native_api_types.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <thread>
#include <sys/time.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 2048

#define VPN_LOG_TAG "NetMgrVpn"
#define VPN_LOG_DOMAIN 0x15b0
#define MAKE_FILE_NAME (strrchr(__FILE__, '/') + 1)

#define NETMANAGER_VPN_LOGE(fmt, ...)                                                                                  \
    OH_LOG_Print(LOG_APP, LOG_ERROR, VPN_LOG_DOMAIN, VPN_LOG_TAG, "vpn [%{public}s %{public}d] " fmt, MAKE_FILE_NAME,  \
                 __LINE__, ##__VA_ARGS__)

#define NETMANAGER_VPN_LOGI(fmt, ...)                                                                                  \
    OH_LOG_Print(LOG_APP, LOG_INFO, VPN_LOG_DOMAIN, VPN_LOG_TAG, "vpn [%{public}s %{public}d] " fmt, MAKE_FILE_NAME,   \
                 __LINE__, ##__VA_ARGS__)

#define NETMANAGER_VPN_LOGD(fmt, ...)                                                                                  \
    OH_LOG_Print(LOG_APP, LOG_DEBUG, VPN_LOG_DOMAIN, VPN_LOG_TAG, "vpn [%{public}s %{public}d] " fmt, MAKE_FILE_NAME,   \
                 __LINE__, ##__VA_ARGS__)

struct FdInfo {
    int32_t tunFd = 0;
    int32_t tunnelFd = 0;
    struct sockaddr_in serverAddr;
};

static FdInfo fdInfo;
static bool threadRunF = false;
static std::thread threadt1;
static std::thread threadt2;

// Obtain the IP address of the UDP server.
static constexpr const int MAX_STRING_LENGTH = 1024;
std::string GetStringFromValueUtf8(napi_env env, napi_value value) {
    std::string result;
    char str[MAX_STRING_LENGTH] = {0};
    size_t length = 0;
    napi_get_value_string_utf8(env, value, str, MAX_STRING_LENGTH, &length);
    if (length > 0) {
        return result.append(str, length);
    }
    return result;
}

void HandleReadTunfd(FdInfo fdInfo) {
    uint8_t buffer[BUFFER_SIZE] = {0};
    while (threadRunF) {
        int ret = read(fdInfo.tunFd, buffer, sizeof(buffer));
        if (ret <= 0) {
            if (errno != 11) {
                NETMANAGER_VPN_LOGE("read tun device error: %{public}d, tunfd: %{public}d", errno, fdInfo.tunFd);
            }
            continue;
        }

        // Read data from the vNIC and send the data to the UDP server through the UDP tunnel.
        NETMANAGER_VPN_LOGD("buffer: %{public}s, len: %{public}d", buffer, ret);
        ret = sendto(fdInfo.tunnelFd, buffer, ret, 0, (struct sockaddr *)&fdInfo.serverAddr, sizeof(fdInfo.serverAddr));
        if (ret <= 0) {
            NETMANAGER_VPN_LOGE("send to server[%{public}s:%{public}d] failed, ret: %{public}d, error: %{public}s",
                                inet_ntoa(fdInfo.serverAddr.sin_addr), ntohs(fdInfo.serverAddr.sin_port), ret,
                                strerror(errno));
            continue;
        }
    }
}

void HandleTcpReceived(FdInfo fdInfo) {
    int addrlen = sizeof(struct sockaddr_in);
    uint8_t buffer[BUFFER_SIZE] = {0};
    while (threadRunF) {
        int length = recvfrom(fdInfo.tunnelFd, buffer, sizeof(buffer), 0, (struct sockaddr *)&fdInfo.serverAddr,
                              (socklen_t *)&addrlen);
        if (length < 0) {
            if (errno != 11) {
                NETMANAGER_VPN_LOGE("read tun device error: %{public}d, tunnelfd: %{public}d", errno, fdInfo.tunnelFd);
            }
            continue;
        }

        // Receive data from the UDP server and write the data to the vNIC.
        NETMANAGER_VPN_LOGD("from [%{public}s:%{public}d] data: %{public}s, len: %{public}d",
                            inet_ntoa(fdInfo.serverAddr.sin_addr), ntohs(fdInfo.serverAddr.sin_port), buffer, length);
        int ret = write(fdInfo.tunFd, buffer, length);
        if (ret <= 0) {
            NETMANAGER_VPN_LOGE("error Write To Tunfd, errno: %{public}d", errno);
        }
    }
}

static napi_value UdpConnect(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);

    int32_t port = 0;
    napi_get_value_int32(env, args[1], &port);
    std::string ipAddr = GetStringFromValueUtf8(env, args[0]);

    NETMANAGER_VPN_LOGI("ip: %{public}s port: %{public}d", ipAddr.c_str(), port);

    // Establish a UDP tunnel.
    int32_t sockFd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockFd == -1) {
        NETMANAGER_VPN_LOGE("socket() error");
        return 0;
    }

    struct timeval timeout = {1, 0};
    setsockopt(sockFd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(struct timeval));

    memset(&fdInfo.serverAddr, 0, sizeof(fdInfo.serverAddr));
    fdInfo.serverAddr.sin_family = AF_INET;
    fdInfo.serverAddr.sin_addr.s_addr = inet_addr(ipAddr.c_str()); // server's IP addr
    fdInfo.serverAddr.sin_port = htons(port);                      // port

    NETMANAGER_VPN_LOGI("Connection successful");

    napi_value tunnelFd;
    napi_create_int32(env, sockFd, &tunnelFd);
    return tunnelFd;
}

static napi_value StartVpn(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);

    napi_get_value_int32(env, args[0], &fdInfo.tunFd);
    napi_get_value_int32(env, args[1], &fdInfo.tunnelFd);

    if (threadRunF) {
        threadRunF = false;
        threadt1.join();
        threadt2.join();
    }

    // Start two threads. One is used to read data from the vNIC, and the other is used to receive data from the server.
    threadRunF = true;
    std::thread tt1(HandleReadTunfd, fdInfo);
    std::thread tt2(HandleTcpReceived, fdInfo);

    threadt1 = std::move(tt1);
    threadt2 = std::move(tt2);

    NETMANAGER_VPN_LOGI("StartVpn successful");

    napi_value retValue;
    napi_create_int32(env, 0, &retValue);
    return retValue;
}

static napi_value StopVpn(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);

    int32_t tunnelFd;
    napi_get_value_int32(env, args[0], &tunnelFd);
    if (tunnelFd) {
        close(tunnelFd);
        tunnelFd = 0;
    }

    // Stop the two threads.
    if (threadRunF) {
        threadRunF = false;
        threadt1.join();
        threadt2.join();
    }

    NETMANAGER_VPN_LOGI("StopVpn successful");

    napi_value retValue;
    napi_create_int32(env, 0, &retValue);
    return retValue;
}

EXTERN_C_START
static napi_value Init(napi_env env, napi_value exports) {
    napi_property_descriptor desc[] = {
        {"udpConnect", nullptr, UdpConnect, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"startVpn", nullptr, StartVpn, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"stopVpn", nullptr, StopVpn, nullptr, nullptr, nullptr, napi_default, nullptr},
    };
    napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
    return exports;
}
EXTERN_C_END

static napi_module demoModule = {
    .nm_version = 1,
    .nm_flags = 0,
    .nm_filename = nullptr,
    .nm_register_func = Init,
    .nm_modname = "entry",
    .nm_priv = ((void *)0),
    .reserved = {0},
};

extern "C" __attribute__((constructor)) void RegisterEntryModule(void) {
    napi_module_register(&demoModule);
}
```
