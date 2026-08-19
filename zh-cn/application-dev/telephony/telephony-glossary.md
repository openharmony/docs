# Telephony Kit术语
<!--Kit: Telephony Kit-->
<!--Subsystem: Telephony-->
<!--Owner: @shao-yikai-->
<!--Designer: @wnazgul-->
<!--Tester: @jiang_99-->
<!--Adviser: @zhang_yixin13-->

## A

### Access Point Name (APN)；接入点名称

移动通信中标识分组数据网络接入点的字符串，终端建立蜂窝数据连接时必须配置，决定设备经哪个网关接入运营商网络或专网。

## D

### Data SMS；数据短信

携带二进制字节数据而非文本内容的短信，发送时须指定目的端口实现端口寻址，用于终端应用间传输结构化数据（如 WAP Push），与文本短信相区分。

### Default Cellular Data SIM；默认移动数据卡

设备当前用于蜂窝数据业务的指定SIM卡，由slotId标识；双卡设备需指定一张作为默认数据卡，是其他蜂窝数据接口的默认作用对象。

## M

### Multimedia Messaging Service (MMS)；彩信

在移动网络上传输包含文本、图片、音频、视频等多媒体内容消息的业务，与纯文本SMS不同，采用基于WAP/HTTP的PDU封装并经MMSC存储转发。

## V

### vCard；电子名片

表示联系人信息（姓名、电话、地址、URL、照片等）的文件格式标准，OpenHarmony中VCard模块支持将其导入联系人数据库或反向导出。

### vCard File (VCF)；vCard文件

符合vCard标准的联系人信息文件（扩展名.vcf），以纯文本键值对组织联系人字段，用于导入导出操作。

### Voice over LTE (VoLTE)；LTE语音

基于IMS架构在LTE数据承载上提供的语音业务，区别于传统CS域语音，其支持与开关受运营商配置项控制。