# 联网


完成版本编译及烧录后，下面开始介绍如何在串口终端上执行AT命令，使Hi3861 WLAN模组联网。


1. 保持Windows工作台和WLAN模组的连接状态，在DevEco  Device Tool最下方，点击“DevEco:Serial Monitor”按钮。

     **图1** 打开DevEco  Device Tool串口终端示意图  

   ![zh-cn_image_0000001227114644](figures/zh-cn_image_0000001227114644.png)

2. 复位Hi3861 WLAN模组，终端界面显示“ready to OS start”，则启动成功。

     **图2** Hi3861 WLAN模组复位成功示意图
  
   ![zh-cn_image_0000001226794704](figures/zh-cn_image_0000001226794704.png)

3. 在串口终端中，依次执行如下AT命令，启动STA模式，连接指定AP热点，并开启DHCP功能。

   > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
   > 开发板启动后，串口会打印测试用例信息，待测试用例信息打印完成后再执行AT指令，否则AT指令会被测试用例信息覆盖。

     
     
   ```
   AT+STARTSTA                             # 启动STA模式
   AT+SCAN                                 # 扫描周边AP
   AT+SCANRESULT                           # 显示扫描结果
   AT+CONN="SSID",,2,"PASSWORD"            # 连接指定AP，其中SSID/PASSWORD为待连接的热点名称和密码
   AT+STASTAT                              # 查看连接结果
   AT+DHCP=wlan0,1                         # 通过DHCP向AP请求wlan0的IP地址
   ```

4. 查看Hi3861 WLAN模组与网关联通是否正常，如下图所示。
     
   ```
   AT+IFCFG                                # 查看模组接口IP
   AT+PING=X.X.X.X                         # 检查模组与网关的联通性，其中X.X.X.X需替换为实际的网关地址
   ```

     **图3** Hi3861 WLAN模组联网成功示意图  

   ![zh-cn_image_0000001226954648](figures/zh-cn_image_0000001226954648.png)
