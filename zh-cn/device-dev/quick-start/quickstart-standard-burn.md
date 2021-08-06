# 镜像烧录<a name="ZH-CN_TOPIC_0000001119964704"></a>

-   [前提条件](#section63941724112115)
-   [使用网口烧录](#section112807166589)

标准系统烧录，在V2.2 Beta1及以上版本支持。

Hi3516DV300支持烧录标准系统，其烧录方式包括USB烧录、网口烧录和串口烧录三种方式，其中：

-   **Windows系统：支持USB烧录、网口烧录和串口烧录**
-   **Linux系统：支持串口烧录和网口烧录。**

同一种烧录方式（如网口烧录），在Windows和Linux环境下的烧录操作完全一致，区别仅在于DevEco Device Tool环境搭建不同。

>![](../public_sys-resources/icon-note.gif) **说明：** 
>当前Hi3516DV300开发板支持通过网口、USB、串口三种方式烧录OpenHarmony标准系统。本文以网口方式为例讲解烧录操作，其他两种烧录方式请参照[Hi3516DV300烧录指导](https://device.harmonyos.com/cn/docs/ide/user-guides/hi3516_upload-0000001052148681)。

## 前提条件<a name="section63941724112115"></a>

在DevEco Device Tool中[打开一个工程](https://device.harmonyos.com/cn/docs/ide/user-guides/open_project-0000001071680043)，该工程文件夹选择待烧录文件所在文件夹即可。其中开发板类型固定选择Hi3516DV300，Framework选择“Hb”。

## 使用网口烧录<a name="section112807166589"></a>

Hi3516DV300开发板使用网口录方式，支持Windows和Linux系统。

1.  请连接好电脑和待烧录开发板，需要同时连接串口、网口和电源，具体可参考[Hi3516DV300开发板介绍](https://device.harmonyos.com/cn/docs/start/introduce/oem_minitinier_des_3516-0000001152041033)。
2.  <a name="zh-cn_topic_0000001180633781_li1050616379507"></a>打开电脑的设备管理器，查看并记录对应的串口号。

    >![](../public_sys-resources/icon-note.gif) **说明：** 
    >如果对应的串口异常，请根据[Hi3516DV300/Hi3518EV300开发板串口驱动安装指导](https://device.harmonyos.com/cn/docs/ide/user-guides/hi3516_hi3518-drivers-0000001050743695)安装USB转串口的驱动程序。

    ![](figure/zh-cn_image_0000001180513891.png)

3.  打开DevEco Device Tool，在Projects中，点击**Settings**打开工程配置界面。

    ![](figure/2021-01-27_170334-17.png)

4.  在**Partition Configuration**页签中，按照下表内容填写烧录文件信息，包括：

    <a name="zh-cn_topic_0000001180633781_table18494162555410"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001180633781_row15492132518545"><th class="cellrowborder" valign="top" width="12.5%" id="mcps1.1.9.1.1"><p id="zh-cn_topic_0000001180633781_p174911825135413"><a name="zh-cn_topic_0000001180633781_p174911825135413"></a><a name="zh-cn_topic_0000001180633781_p174911825135413"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.5%" id="mcps1.1.9.1.2"><p id="zh-cn_topic_0000001180633781_p114911625165414"><a name="zh-cn_topic_0000001180633781_p114911625165414"></a><a name="zh-cn_topic_0000001180633781_p114911625165414"></a>Binary</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.5%" id="mcps1.1.9.1.3"><p id="zh-cn_topic_0000001180633781_p1749112515417"><a name="zh-cn_topic_0000001180633781_p1749112515417"></a><a name="zh-cn_topic_0000001180633781_p1749112515417"></a>Memory</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.5%" id="mcps1.1.9.1.4"><p id="zh-cn_topic_0000001180633781_p1749182575420"><a name="zh-cn_topic_0000001180633781_p1749182575420"></a><a name="zh-cn_topic_0000001180633781_p1749182575420"></a>System</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.5%" id="mcps1.1.9.1.5"><p id="zh-cn_topic_0000001180633781_p174921325135414"><a name="zh-cn_topic_0000001180633781_p174921325135414"></a><a name="zh-cn_topic_0000001180633781_p174921325135414"></a>Address</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.5%" id="mcps1.1.9.1.6"><p id="zh-cn_topic_0000001180633781_p749242515415"><a name="zh-cn_topic_0000001180633781_p749242515415"></a><a name="zh-cn_topic_0000001180633781_p749242515415"></a>Length</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.5%" id="mcps1.1.9.1.7"><p id="zh-cn_topic_0000001180633781_p164921925115416"><a name="zh-cn_topic_0000001180633781_p164921925115416"></a><a name="zh-cn_topic_0000001180633781_p164921925115416"></a>Board</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.5%" id="mcps1.1.9.1.8"><p id="zh-cn_topic_0000001180633781_p0492132595412"><a name="zh-cn_topic_0000001180633781_p0492132595412"></a><a name="zh-cn_topic_0000001180633781_p0492132595412"></a>Type</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001180633781_row949214259543"><td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.1.9.1.1 "><p id="zh-cn_topic_0000001180633781_p194922259548"><a name="zh-cn_topic_0000001180633781_p194922259548"></a><a name="zh-cn_topic_0000001180633781_p194922259548"></a>fastboot</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.1.9.1.2 "><p id="zh-cn_topic_0000001180633781_p749222515411"><a name="zh-cn_topic_0000001180633781_p749222515411"></a><a name="zh-cn_topic_0000001180633781_p749222515411"></a>选择“u-boot-hi3516dv300_emmc.bin”</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.1.9.1.3 "><p id="zh-cn_topic_0000001180633781_p1749213258540"><a name="zh-cn_topic_0000001180633781_p1749213258540"></a><a name="zh-cn_topic_0000001180633781_p1749213258540"></a>emmc</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.1.9.1.4 "><p id="zh-cn_topic_0000001180633781_p1749220254548"><a name="zh-cn_topic_0000001180633781_p1749220254548"></a><a name="zh-cn_topic_0000001180633781_p1749220254548"></a>none</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.1.9.1.5 "><p id="zh-cn_topic_0000001180633781_p144921825125418"><a name="zh-cn_topic_0000001180633781_p144921825125418"></a><a name="zh-cn_topic_0000001180633781_p144921825125418"></a>0x000000</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.1.9.1.6 "><p id="zh-cn_topic_0000001180633781_p549272518547"><a name="zh-cn_topic_0000001180633781_p549272518547"></a><a name="zh-cn_topic_0000001180633781_p549272518547"></a>0x100000</p>
    </td>
    <td class="cellrowborder" rowspan="7" valign="top" width="12.5%" headers="mcps1.1.9.1.7 "><p id="zh-cn_topic_0000001180633781_p9492125205411"><a name="zh-cn_topic_0000001180633781_p9492125205411"></a><a name="zh-cn_topic_0000001180633781_p9492125205411"></a>固定选择“hi3516dv300”</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.1.9.1.8 "><p id="zh-cn_topic_0000001180633781_p1549282518548"><a name="zh-cn_topic_0000001180633781_p1549282518548"></a><a name="zh-cn_topic_0000001180633781_p1549282518548"></a>NA</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001180633781_row94933253545"><td class="cellrowborder" valign="top" headers="mcps1.1.9.1.1 "><p id="zh-cn_topic_0000001180633781_p1749311252542"><a name="zh-cn_topic_0000001180633781_p1749311252542"></a><a name="zh-cn_topic_0000001180633781_p1749311252542"></a>boot</p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.1.9.1.2 "><p id="zh-cn_topic_0000001180633781_p18493162515543"><a name="zh-cn_topic_0000001180633781_p18493162515543"></a><a name="zh-cn_topic_0000001180633781_p18493162515543"></a>选择“uImage”</p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.1.9.1.3 "><p id="zh-cn_topic_0000001180633781_p1249332512548"><a name="zh-cn_topic_0000001180633781_p1249332512548"></a><a name="zh-cn_topic_0000001180633781_p1249332512548"></a>emmc</p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.1.9.1.4 "><p id="zh-cn_topic_0000001180633781_p114931825155414"><a name="zh-cn_topic_0000001180633781_p114931825155414"></a><a name="zh-cn_topic_0000001180633781_p114931825155414"></a>none</p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.1.9.1.5 "><p id="zh-cn_topic_0000001180633781_p1249392565417"><a name="zh-cn_topic_0000001180633781_p1249392565417"></a><a name="zh-cn_topic_0000001180633781_p1249392565417"></a>0x100000</p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.1.9.1.6 "><p id="zh-cn_topic_0000001180633781_p84932253541"><a name="zh-cn_topic_0000001180633781_p84932253541"></a><a name="zh-cn_topic_0000001180633781_p84932253541"></a>0xf00000</p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.1.9.1.7 "><p id="zh-cn_topic_0000001180633781_p13493142515412"><a name="zh-cn_topic_0000001180633781_p13493142515412"></a><a name="zh-cn_topic_0000001180633781_p13493142515412"></a>NA</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001180633781_row649362515548"><td class="cellrowborder" valign="top" headers="mcps1.1.9.1.1 "><p id="zh-cn_topic_0000001180633781_p749317258546"><a name="zh-cn_topic_0000001180633781_p749317258546"></a><a name="zh-cn_topic_0000001180633781_p749317258546"></a>updater</p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.1.9.1.2 "><p id="zh-cn_topic_0000001180633781_p749372519545"><a name="zh-cn_topic_0000001180633781_p749372519545"></a><a name="zh-cn_topic_0000001180633781_p749372519545"></a>选择“updater.img”</p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.1.9.1.3 "><p id="zh-cn_topic_0000001180633781_p34931825165414"><a name="zh-cn_topic_0000001180633781_p34931825165414"></a><a name="zh-cn_topic_0000001180633781_p34931825165414"></a>emmc</p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.1.9.1.4 "><p id="zh-cn_topic_0000001180633781_p104932253549"><a name="zh-cn_topic_0000001180633781_p104932253549"></a><a name="zh-cn_topic_0000001180633781_p104932253549"></a>ext3/4</p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.1.9.1.5 "><p id="zh-cn_topic_0000001180633781_p1149310255541"><a name="zh-cn_topic_0000001180633781_p1149310255541"></a><a name="zh-cn_topic_0000001180633781_p1149310255541"></a>0x1000000</p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.1.9.1.6 "><p id="zh-cn_topic_0000001180633781_p194936251542"><a name="zh-cn_topic_0000001180633781_p194936251542"></a><a name="zh-cn_topic_0000001180633781_p194936251542"></a>0x1400000</p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.1.9.1.7 "><p id="zh-cn_topic_0000001180633781_p1849352575412"><a name="zh-cn_topic_0000001180633781_p1849352575412"></a><a name="zh-cn_topic_0000001180633781_p1849352575412"></a>NA</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001180633781_row1149316252542"><td class="cellrowborder" valign="top" headers="mcps1.1.9.1.1 "><p id="zh-cn_topic_0000001180633781_p114931925205416"><a name="zh-cn_topic_0000001180633781_p114931925205416"></a><a name="zh-cn_topic_0000001180633781_p114931925205416"></a>misc</p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.1.9.1.2 "><p id="zh-cn_topic_0000001180633781_p149318253541"><a name="zh-cn_topic_0000001180633781_p149318253541"></a><a name="zh-cn_topic_0000001180633781_p149318253541"></a>空白，不用选择</p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.1.9.1.3 "><p id="zh-cn_topic_0000001180633781_p64931825145418"><a name="zh-cn_topic_0000001180633781_p64931825145418"></a><a name="zh-cn_topic_0000001180633781_p64931825145418"></a>emmc</p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.1.9.1.4 "><p id="zh-cn_topic_0000001180633781_p1149372535411"><a name="zh-cn_topic_0000001180633781_p1149372535411"></a><a name="zh-cn_topic_0000001180633781_p1149372535411"></a>none</p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.1.9.1.5 "><p id="zh-cn_topic_0000001180633781_p64931253544"><a name="zh-cn_topic_0000001180633781_p64931253544"></a><a name="zh-cn_topic_0000001180633781_p64931253544"></a>0x2400000</p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.1.9.1.6 "><p id="zh-cn_topic_0000001180633781_p194932025195413"><a name="zh-cn_topic_0000001180633781_p194932025195413"></a><a name="zh-cn_topic_0000001180633781_p194932025195413"></a>0x100000</p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.1.9.1.7 "><p id="zh-cn_topic_0000001180633781_p1649332565414"><a name="zh-cn_topic_0000001180633781_p1649332565414"></a><a name="zh-cn_topic_0000001180633781_p1649332565414"></a>NA</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001180633781_row16494182510545"><td class="cellrowborder" valign="top" headers="mcps1.1.9.1.1 "><p id="zh-cn_topic_0000001180633781_p64948251549"><a name="zh-cn_topic_0000001180633781_p64948251549"></a><a name="zh-cn_topic_0000001180633781_p64948251549"></a>system</p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.1.9.1.2 "><p id="zh-cn_topic_0000001180633781_p104948254549"><a name="zh-cn_topic_0000001180633781_p104948254549"></a><a name="zh-cn_topic_0000001180633781_p104948254549"></a>选择“system.img”</p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.1.9.1.3 "><p id="zh-cn_topic_0000001180633781_p5494122517543"><a name="zh-cn_topic_0000001180633781_p5494122517543"></a><a name="zh-cn_topic_0000001180633781_p5494122517543"></a>emmc</p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.1.9.1.4 "><p id="zh-cn_topic_0000001180633781_p84948259549"><a name="zh-cn_topic_0000001180633781_p84948259549"></a><a name="zh-cn_topic_0000001180633781_p84948259549"></a>ext3/4</p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.1.9.1.5 "><p id="zh-cn_topic_0000001180633781_p1249432519541"><a name="zh-cn_topic_0000001180633781_p1249432519541"></a><a name="zh-cn_topic_0000001180633781_p1249432519541"></a>0x2500000</p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.1.9.1.6 "><p id="zh-cn_topic_0000001180633781_p154941125205415"><a name="zh-cn_topic_0000001180633781_p154941125205415"></a><a name="zh-cn_topic_0000001180633781_p154941125205415"></a>0xceb00000</p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.1.9.1.7 "><p id="zh-cn_topic_0000001180633781_p24941925205415"><a name="zh-cn_topic_0000001180633781_p24941925205415"></a><a name="zh-cn_topic_0000001180633781_p24941925205415"></a>NA</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001180633781_row10494202535417"><td class="cellrowborder" valign="top" headers="mcps1.1.9.1.1 "><p id="zh-cn_topic_0000001180633781_p3494225175414"><a name="zh-cn_topic_0000001180633781_p3494225175414"></a><a name="zh-cn_topic_0000001180633781_p3494225175414"></a>vendor</p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.1.9.1.2 "><p id="zh-cn_topic_0000001180633781_p6494192516544"><a name="zh-cn_topic_0000001180633781_p6494192516544"></a><a name="zh-cn_topic_0000001180633781_p6494192516544"></a>选择“vendor.img”</p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.1.9.1.3 "><p id="zh-cn_topic_0000001180633781_p549492595415"><a name="zh-cn_topic_0000001180633781_p549492595415"></a><a name="zh-cn_topic_0000001180633781_p549492595415"></a>emmc</p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.1.9.1.4 "><p id="zh-cn_topic_0000001180633781_p1494122595420"><a name="zh-cn_topic_0000001180633781_p1494122595420"></a><a name="zh-cn_topic_0000001180633781_p1494122595420"></a>ext3/4</p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.1.9.1.5 "><p id="zh-cn_topic_0000001180633781_p04941925115412"><a name="zh-cn_topic_0000001180633781_p04941925115412"></a><a name="zh-cn_topic_0000001180633781_p04941925115412"></a>0xd1000000</p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.1.9.1.6 "><p id="zh-cn_topic_0000001180633781_p749416252545"><a name="zh-cn_topic_0000001180633781_p749416252545"></a><a name="zh-cn_topic_0000001180633781_p749416252545"></a>0x10000000</p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.1.9.1.7 "><p id="zh-cn_topic_0000001180633781_p134941725175414"><a name="zh-cn_topic_0000001180633781_p134941725175414"></a><a name="zh-cn_topic_0000001180633781_p134941725175414"></a>NA</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001180633781_row349412251547"><td class="cellrowborder" valign="top" headers="mcps1.1.9.1.1 "><p id="zh-cn_topic_0000001180633781_p19494122585417"><a name="zh-cn_topic_0000001180633781_p19494122585417"></a><a name="zh-cn_topic_0000001180633781_p19494122585417"></a>userdata</p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.1.9.1.2 "><p id="zh-cn_topic_0000001180633781_p14494192514543"><a name="zh-cn_topic_0000001180633781_p14494192514543"></a><a name="zh-cn_topic_0000001180633781_p14494192514543"></a>选择“userdata.img”</p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.1.9.1.3 "><p id="zh-cn_topic_0000001180633781_p15494725175416"><a name="zh-cn_topic_0000001180633781_p15494725175416"></a><a name="zh-cn_topic_0000001180633781_p15494725175416"></a>emmc</p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.1.9.1.4 "><p id="zh-cn_topic_0000001180633781_p154946254549"><a name="zh-cn_topic_0000001180633781_p154946254549"></a><a name="zh-cn_topic_0000001180633781_p154946254549"></a>ext3/4</p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.1.9.1.5 "><p id="zh-cn_topic_0000001180633781_p204941225155420"><a name="zh-cn_topic_0000001180633781_p204941225155420"></a><a name="zh-cn_topic_0000001180633781_p204941225155420"></a>0xe1000000</p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.1.9.1.6 "><p id="zh-cn_topic_0000001180633781_p1449482515413"><a name="zh-cn_topic_0000001180633781_p1449482515413"></a><a name="zh-cn_topic_0000001180633781_p1449482515413"></a>0x5b800000</p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.1.9.1.7 "><p id="zh-cn_topic_0000001180633781_p0494182535420"><a name="zh-cn_topic_0000001180633781_p0494182535420"></a><a name="zh-cn_topic_0000001180633781_p0494182535420"></a>NA</p>
    </td>
    </tr>
    </tbody>
    </table>

    ![](figure/zh-cn_image_0000001180633813.png)

5.  在“hi3516dv300”页签，设置烧录选项，包括upload\_port、upload\_partitions和upload\_protocol。

    -   upload\_port：选择步骤[2](#zh-cn_topic_0000001180633781_li1050616379507)中查询的串口号。
    -   upload\_protocol：选择烧录协议，固定选择“hiburn-net”。
    -   upload\_partitions：选择待烧录的文件，包括fastboot、boot、updater、misc、system、vendor和userdata。

    ![](figure/zh-cn_image_0000001134474510.png)

6.  检查和设置连接开发板后的网络适配器的IP地址信息，设置方法请参考[设置Hi3516DV300网口烧录的IP地址信息](https://device.harmonyos.com/cn/docs/ide/user-guides/set_ipaddress-0000001141825075)。
7.  设置网口烧录的IP地址信息，设置如下选项：

    -   upload\_net\_server\_ip：选择步骤6中设置的IP地址信息。例如192.168.1.2
    -   upload\_net\_client\_mask：设置开发板的子网掩码，工具会自动根据选择的upload\_net\_server\_ip进行设置。例如255.255.255.0
    -   upload\_net\_client\_gw：设置开发板的网关，工具会自动根据选择的upload\_net\_server\_ip进行设置。例如192.168.1.1
    -   upload\_net\_client\_ip：设置开发板的IP地址，工具会自动根据选择的upload\_net\_server\_ip进行设置。例如192.168.1.3

    ![](figure/zh-cn_image_0000001180633847.png)

8.  所有的配置都修改完成后，在工程配置页签的顶部，点击**Save**进行保存。
9.  启动烧录后，显示如下提示信息时，请重启开发板（下电再上电）。

    ![](figure/zh-cn_image_0000001134634288.png)

10. 重新上电后，启动烧录，界面提示如下信息时，表示烧录成功。

    ![](figure/zh-cn_image_0000001180513893.png)


