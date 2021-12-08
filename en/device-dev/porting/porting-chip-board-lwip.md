# lwIP Module Adaptation<a name="EN-US_TOPIC_0000001172881086"></a>

Lightweight IP (lwIP) is an open-source TCP/IP stack designed for embedded systems. LiteOS-M has adapted to lwIP and provides enhanced lwIP features. The lwIP code consists of the following:

- lwIP source code in the **third_party/lwip** directory: Only a few intrusive modifications have been made for enhanced features.

- Code for lwIP adaptation and enhancement in the **kernel/liteos_m/components/net/lwip-2.1** directory: The default lwIP configuration file is provided.

If you want to use the lwIP module, perform the following steps to complete adaptation:

1. Create a folder, for example, **lwip_adapter**, in the product directory to store configuration files.

2. Copy **include** and **build.gn** in the **kernel/liteos\_m/components/net/lwip-2.1/porting** directory to the **lwip_adapter** folder.

3. Modify the configuration file if the default configuration cannot meet service requirements. For example, to disable the DHCP function, change the value of the macro **LWIP\_DHCP** in **lwip\_adapter/include/lwip/lwipopts.h** from **1** to **0**.

    ```
    //#define LWIP_DHCP                       1
    #define LWIP_DHCP                       0
    ```

4. Change the value of **LWIP\_PORTING\_INCLUDE\_DIRS** in **lwip\_adapter/BUILD.gn** to the **include** directory in **lwip\_adapter**.

    ```
    #include_dirs += LWIP_PORTING_INCLUDE_DIRS
    include_dirs += "//xxx/lwip_adapter/include"
    ```

5. Set the lwIP switch and build path in the product configuration file, for example, **config.json**.

    ```
    {
      "subsystem": "kernel",
      "components": [
        { "component": "liteos_m", "features":["enable_ohos_kernel_liteos_m_lwip = true", "ohos_kernel_liteos_m_lwip_path = \"//xxx/lwip_adapter:lwip\"" ] }
      ]
    },
    ```

6. If other modules need to reference the lwIP header file, ensure that the header file path contains the following two parts and the sequence cannot be changed:

    ```
    include_dir = [
      "//xxx/lwip_adapter/include", # Path in step 4
      "//third_party/lwip/src/include",
    ]
    ```
