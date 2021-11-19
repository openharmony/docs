# lwIP组件适配<a name="ZH-CN_TOPIC_0000001172881086"></a>

lwIP是一个小型开源的TCP/IP协议栈，LiteOS-M已对开源lwIP做了适配和功能增强，lwIP代码分为两部分：

- third_party/lwip目录下是lwIP开源代码，里面只做了少量的侵入式修改，为了适配增强功能。

- kernel/liteos_m/components/net/lwip-2.1目录下是lwIP适配和功能增强代码，里面提供了lwIP的默认配置文件。

如果需要使用lwIP组件，请按如下步骤适配：

1. 在产品目录下新建一个目录用来存放配置文件，如lwip_adapter。

2. 将kernel/liteos_m/components/net/lwip-2.1/porting目录下的include目录和build.gn复制到步骤1的lwip_adapter目录下。

3. 如果默认配置不能满足产品使用，可根据产品使用情况修改对应的配置，如关闭DHCP功能，将lwip_adapter/include/lwip/lwipopts.h中宏LWIP_DHCP的值由1改为0。

    ```
    //#define LWIP_DHCP                       1
    #define LWIP_DHCP                       0
    ```

4. 将lwip_adapter/BUILD.gn里的LWIP_PORTING_INCLUDE_DIRS修改为步骤1中lwip_adapter目录下的include路径。

    ```
    #include_dirs += LWIP_PORTING_INCLUDE_DIRS
    include_dirs += "//xxx/lwip_adapter/include"
    ```

5. 在产品的配置文件中设置编译lwIP的开关和编译路径，如config.json。

    ```
    {
      "subsystem": "kernel",
      "components": [
        { "component": "liteos_m", "features":["enable_ohos_kernel_liteos_m_lwip = true", "ohos_kernel_liteos_m_lwip_path = \"//xxx/lwip_adapter:lwip\"" ] }
      ]
    },
    ```

6. 其他模块需要引用lwIP头文件时，头文件路径应该包含如下两个部分，且顺序不能变。

    ```
    include_dir = [
      "//xxx/lwip_adapter/include", #步骤4里的路径
      "//third_party/lwip/src/include",
    ]
    ```

