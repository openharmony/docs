# lwIP Module Adaptation<a name="EN-US_TOPIC_0000001172881086"></a>

Lightweight IP (lwIP) is an open-source TCP/IP stack designed for embedded systems. LiteOS-M has adapted to lwIP and provides enhanced lwIP features. The lwIP code consists of the following:

- lwIP source code in the **third_party/lwip** directory: Only a few intrusive modifications have been made for enhanced features.

- Code for lwIP adaptation and enhancement in the **kernel/liteos_m/components/net/lwip-2.1** directory: The default lwIP configuration file is provided.

If you want to use the lwIP module, perform the following steps to complete adaptation:

1. Create a directory, for example, **lwip_adapter**, in the device directory to store its adaptation files.

2. Create the **include** directory in the **lwip_adapter** directory to store the adaptation header files.

3. Create the **lwip** directory in the **include** directory and then create the header file **lwipopts.h** in the **lwip** directory. The code is as follows. If the default configuration cannot meet service requirements, modify the configuration, for example, disable the DHCP function.

    ```
    #ifndef _LWIP_ADAPTER_LWIPOPTS_H_
    #define _LWIP_ADAPTER_LWIPOPTS_H_

    #include_next "lwip/lwipopts.h"

    #undef LWIP_DHCP
    #define LWIP_DHCP                       0 // Disable the DHCP function.

    #endif /* _LWIP_ADAPTER_LWIPOPTS_H_ */
    ```

4. Copy **BUILD.gn** in the **kernel/liteos_m/components/net/lwip-2.1/porting** directory to the **lwip_adapter** directory and modify the file as follows:

    ```
    import("//kernel/liteos_m/liteos.gni")
    import("$LITEOSTHIRDPARTY/lwip/lwip.gni")
    import("$LITEOSTOPDIR/components/net/lwip-2.1/lwip_porting.gni")

    module_switch = defined(LOSCFG_NET_LWIP_SACK)
    module_name = "lwip"
    kernel_module(module_name) {
      sources = LWIP_PORTING_FILES + LWIPNOAPPSFILES - [ "$LWIPDIR/api/sockets.c" ]
      include_dirs = [ "//utils/native/lite/include" ]
    }

    # Add include, the directory of the new adaptation header file.
    config("public") {
      include_dirs = [ "include" ] + LWIP_PORTING_INCLUDE_DIRS + LWIP_INCLUDE_DIRS
    }
    ```

5. In the device configuration file (for example, **config.json**), set the lwIP build path to the path of **BUILD.gn** in step 4.

    ```
    {
      "subsystem": "kernel",
      "components": [
        { "component": "liteos_m", "features":["ohos_kernel_liteos_m_lwip_path = \"//xxx/lwip_adapter\"" ] }
      ]
    },
    ```

6. In the kernel build configuration file of the device, for example, **kernel_config/debug.config**, enable lwIP build.

    ```
    LOSCFG_NET_LWIP=y
    ```
