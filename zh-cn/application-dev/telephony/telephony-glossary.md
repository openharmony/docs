# Telephony Kit术语

## #

### 3rd Generation Partnership Project (3GPP)；第三代合作伙伴计划

制定 GSM/UMTS/LTE/NR 等移动通信标准的国际标准化组织，其规范覆盖 SIM/USIM、IMS、SMS、USAT 等，是 3GPP 体系网络（对应 IMEI）的协议基础，与 3GPP2 并列运作。

### 3rd Generation Partnership Project 2 (3GPP2)；第三代合作伙伴计划2

制定 cdmaOne/CDMA2000/EVDO 等 CDMA 移动通信标准的标准化组织，与 3GPP 并行运作，其规范网络（对应 MEID）的短信 PDU 结构与 3GPP 不同。

### 5G Core (5GC)；5G核心网

3GPP R15 起定义的 5G 核心网，采用服务化架构并支持网络切片与控制面/用户面分离，与 NG-RAN 配合构成 SA 组网，是 5G 完整能力的基础，区别于 4G EPC 核心网。

## A

### Abbreviated Dialling Numbers (ADN)；缩位拨号

存储在 SIM 卡电话簿文件中的联系人条目，每条含名称与号码，是卡上通用电话簿的标准实现，与固定拨号（FDN）相对。

### Absolute Radio Frequency Channel Number (ARFCN)；绝对无线频率信道号

GSM/UMTS 中标识载波频点的整数编号，结合频段指示可换算载波绝对频率，用于 2G/3G 网络频点扫描与小区接入。

### Access Point Name (APN)；接入点名称

移动通信中标识分组数据网络接入点的字符串，终端建立蜂窝数据连接时必须配置，决定设备经哪个网关接入运营商网络或专网。

### Activation Code；激活码

eSIM 配置文件下载流程中由运营商提供的标识串，配合确认码向 SM-DP+ 服务器发起下载请求；不基于激活码的配置文件该字段可为空。

### Atomic Service；原子化服务

HarmonyOS 中免安装、即点即用的轻量化服务形态。本 Kit 中标注“原子化服务 API”的接口表示自指定 API 版本起可在原子化服务中调用，区别于需安装的普通应用。

## B

### Base Station Identity Code (BSIC)；基站识别号

GSM 中区分相邻基站的 6 位识别码，由网络色码（NCC）与基站色码（BCC）组成，帮助终端在频点相同的小区中区分归属基站。

### Baseband；基带

未经射频调制的低频原始信号及其对应的 Modem 软硬件处理子系统，基带版本号反映 Modem 固件版本，决定终端对无线接入技术、频段、协议特性的支持能力。

### Bound Profile Package (BPP)；绑定配置文件包

SM-DP+ 服务器认证通过后下发的、已与目标 eUICC 绑定的配置文件包，包含可在 eUICC 上安装的全部内容，是配置文件下载流程的关键中间产物。

## C

### Call Transfer；呼叫转移

电话系统中将来电按预设条件自动转接至另一号码的功能，分无条件转移、忙线转移、无回复转移、无法访问转移四种类型，用于用户无法接听时将来电转至其他号码。

### Carrier Aggregation (CA)；载波聚合

将多个载波分量聚合使用以扩展带宽和提升峰值速率的技术，是 LTE/NR 提升吞吐量的关键手段，NetworkState 中以 isCaActive 字段标识其激活状态。

### Cell；小区

蜂窝网络中由单个基站扇区覆盖的无线电区域，是移动网络进行位置管理与切换的最小地理单元，终端通过驻留小区接入网络。

### Cell Broadcast (CB)；小区广播

移动网络向特定地理区域内所有终端同时广播短消息的服务，常用于紧急告警与公共通知，不需知道接收方号码，与点对点短信不同。

### Cell Global Identity (CGI)；小区全球标识

全球唯一标识 2G/3G 小区的编号，由 LAC 与 CI 组合而成，是网络定位终端所在小区的核心参数，在 LTE/NR 中由 ECGI/NCI 对应。

### Cellular Data；蜂窝数据

通过移动通信网络（如 4G/5G）提供的分组数据业务，区别于 Wi-Fi，使设备在无无线局域网时仍可上网，是 Telephony Kit 的核心管理对象。

### Circuit Switched (CS)；电路交换

蜂窝通信中通过独占专用电路资源承载话音、短信等实时业务的交换方式，与分组交换（PS）相对，传统 2G/3G 网络主要依靠该方式提供语音业务。

### Code Division Multiple Access (CDMA)；码分多址

以扩频码区分用户的无线多址接入技术，是 cdmaOne 及 CDMA2000 系列的空口基础，与 GSM/WCDMA 体系并存，主要用于北美及部分亚洲运营商网络。

### Concatenated SMS；长短信

内容超过单条 SMS 最大容量时被拆分为多个分片发送、接收时再合并还原的短信形式，分片通过用户数据头（UDH）携带拼接信息。

### Confirmation Code；确认码

eSIM 配置文件下载过程中由运营商提供给用户的一次性校验码，用于在下载与安装阶段向服务器证明用户授权。

## D

### Data SMS；数据短信

携带二进制字节数据而非文本内容的短信，发送时须指定目的端口实现端口寻址，用于终端应用间传输结构化数据（如 WAP Push），与文本短信相区分。

### Default Cellular Data SIM；默认移动数据卡

设备当前用于蜂窝数据业务的指定 SIM 卡，由 slotId 标识；双卡设备需指定一张作为默认数据卡，是其他蜂窝数据接口的默认作用对象。

### Dual SIM Dual Active (DSDA)；双卡双待双通

双卡双待（DSDS）V5 模式之一，允许两张 SIM 卡同时处于激活并收发信号的状态，避免一卡通话时另一卡无法接入，依赖射频与基带并行支持。

### Dual SIM Dual Standby (DSDS)；双卡双待

设备支持两张 SIM 卡同时待机但同一时刻仅一卡进行业务的能力，分 V2、V3、V5_TDM、V5_DSDA 四种模式，由设备硬件能力决定。

## E

### E.164

ITU-T 制定的国际公共电信编号标准，规定电话号码的国际通用表示形式，号码以“+”加国家码开头、最长 15 位，用于跨国家、跨网络场景下的统一标识与路由寻址。

### E-UTRA Absolute Radio Frequency Channel Number (EARFCN)；演进的绝对无线频率信道号

LTE 中标识 E-UTRA 载波频点的编号，由频段指示与频偏确定载波绝对频率，是 LTE 小区频点描述与测量上报的基础参数。

### E-UTRA NR Dual Connectivity (ENDC)；新无线电双连接

3GPP 定义的双连接技术，LTE 作为主节点、NR 作为辅节点同时为终端提供空口资源，是 NSA 组网的核心实现方式。

### EAP-AKA

基于 3GPP AKA 算法封装在 EAP 协议中的 SIM 卡鉴权类型，用于 WLAN/移动网融合场景下利用 USIM 根密钥完成网络与终端双向认证，区别于基于 2G SIM 算法的 EAP-SIM。

### EAP-SIM

基于 2G SIM 卡算法（GSM A3/A8）封装在 EAP 协议中的鉴权类型，用于 WLAN 等接入网借助 SIM 凭证完成接入认证，与 EAP-AKA 共用接口但底层算法不同。

### Embedded SIM (eSIM)；嵌入式SIM卡

以 eUICC 为载体、可通过 SM-DP+ 远程下载配置文件而无需更换实体卡的 SIM 形态，区别于可插拔的物理 SIM 卡。

### Embedded Universal Integrated Circuit Card (eUICC)；嵌入式通用集成电路卡

支持远程配置文件下载、删除、启用的可编程 SIM 卡硬件，是 eSIM 的物理载体，其上可驻留多个配置文件，由 EID 唯一标识。

### Emergency Call；紧急呼叫

在未注册网络或无 SIM 卡等受限场景下仍允许拨打的特殊呼叫，仅可接入紧急服务号码，是蜂窝网络对终端的最低保障机制。

### Envelope Command；信封命令

SIM 应用工具包（USAT）中终端通过 ME→UICC 通道发送给 SIM 卡的应用层命令，用于将设备事件（菜单选择、呼叫控制等）传递给卡侧应用，区别于终端响应。

### eUICC Identifier (EID)；eUICC识别码

唯一标识一片 eUICC 硬件的固定长度码字，作用类似 SIM 卡的 ICCID，但绑定在不可移除的 eUICC 上。

### Evolution Data Optimized (EVDO)；演进数据优化

CDMA2000 1X EV-DO 的简称，专门承载数据业务的 CDMA 高速分组数据空口，与承担话音的 1XRTT 分工。

### Evolved High Rate Packet Data (EHRPD)；演进高速率分组数据

HRPD（EVDO）的演进版本，可与 LTE 核心网 EPC 互通，使 CDMA 运营商向 LTE 演进时保持数据会话连续性。

## F

### Fixed Dialling Number (FDN)；固定拨号

SIM 卡中限定只能拨打预设号码列表的电话簿类型，启用后非列表内号码被禁止拨出，与通用联系人（ADN）相对，操作通常需 PIN2 密码。

## G

### Generic Bootstrapping Architecture (GBA)；通用引导架构

3GPP 定义的基于 AKA 机制在终端与业务服务器间建立共享密钥的引导框架，IMS 业务可基于其完成终端与业务网认证。

### Global System for Mobile Communication (GSM)；全球移动通信系统

2G 数字蜂窝标准，采用 TDMA 接入，主要承载 CS 域话音、短信及低速 GPRS/EDGE 数据业务，是 WCDMA/LTE 的演进起点。

### GSM 7-bit；GSM 7位编码

GSM 短信默认的字符编码方案，每字符 7 位，使单条 SMS 在 140 字节 PDU 中可容纳 160 个字符，仅适用于 GSM 默认字母表；含非该字母表字符（如中文）时需改用 UCS-2 编码。

### Group Identifier Level 1 (GID1)；组标识符级别1

存储在 SIM 卡 EF_GID1 文件中的标识符，运营商用于区分同一 MCC+MNC 下不同业务子群，常与 GID2 组合用于精细化业务路由。

### Group Identifier Level 2 (GID2)；组标识符级别2

存储在 SIM 卡 EF_GID2 文件中的次级组标识符，与 GID1 配合对同一运营商下用户群进行更细粒度划分。

## I

### Integrated Circuit Card (ICC)；集成电路卡

泛指 SIM/USIM/UICC 等智能卡的通用术语，承载运营商账户与鉴权信息，observer 中 iccAccountInfoChange 事件即基于此命名以统一抽象各类 IC 卡。

### Integrated Circuit Card Identifier (ICCID)；集成电路卡标识符

SIM/eUICC 卡的唯一识别码，由发卡方写入，含发卡方国家、运营商、序列号、校验位等信息，是 eSIM 配置文件操作的定位键。

### Interworking Wireless LAN (IWLAN)；无线局域网接入

通过 WLAN 接入 EPC/IMS 核心网承载 VoWiFi 等业务的接入方式，使终端在蜂窝信号弱时仍可使用语音和数据业务，作为一种 IMS 注册技术与 3GPP 蜂窝接入并列。

### International Mobile Equipment Identity (IMEI)；国际移动设备识别码

3GPP 规范定义的 15 位设备唯一识别码，与 SIM 卡解耦，用于网络识别终端硬件，运营商可据此进行黑白名单管理。

### International Mobile Equipment Identity - Software Version (IMEISV)；国际移动设备软件版本号

在 IMEI 基础上附加软件版本号的设备识别码，用于跟踪设备当前固件/软件版本，常用于远程诊断与版本管理。

### International Mobile Subscriber Identity (IMSI)；国际移动用户识别码

3GPP 网络中唯一标识移动用户的号码，由 MCC、MNC、MSIN 组成，存于 SIM 卡中，是用户身份认证与接入的核心凭据。

### IP Multimedia Services Identity Module (ISIM)；IP多媒体服务身份模块

专为 IMS 应用设计的 SIM 卡应用模块，存储 IMS 用户私有身份（IMPI）、公有身份（IMPU）、家庭网络域名等参数，可独立于 USIM 存在。

### IP Multimedia Subsystem (IMS)；IP多媒体子系统

3GPP 定义的基于 IP 的多媒体业务控制架构，运行于 PS 域之上，为 VoLTE、VoNR、IMS 短信等业务提供注册、会话控制与 QoS 保障。

## L

### Location Area Code (LAC)；位置区编号

2G/3G CS 域中标识位置区的编号，网络通过 LAC 进行寻呼，终端跨 LAC 移动时触发位置更新，是 CS 域移动性管理的基本单位，与 PS 域的 TAC 相对应。

### Long Term Evolution (LTE)；长期演进

3GPP R8 起定义的 4G 无线接入技术，采用 OFDMA 与 MIMO 提供高速分组数据业务，端到端全 IP 架构仅保留 PS 域，是 5G NR 的锚点与演进基准。

## M

### Mobile Country Code (MCC)；移动国家码

PLMN 标识的前 3 位数字，由 ITU 分配，用于全球唯一标识移动网络所在国家（如 460 代表中国），是 PLMN、IMSI 等的核心组成部分。

### Mobile Equipment Identifier (MEID)；移动设备识别码

CDMA 制式设备的 14 位十六进制唯一识别码，作用与 IMEI 对应但用于 3GPP2 网络，是 CDMA 终端的全球唯一硬件标识。

### Mobile Network Code (MNC)；移动网络码

PLMN 标识中跟在 MCC 之后的 2~3 位数字，由各国通信管理部门分配，用于区分同一国家内不同运营商，与 MCC 组合构成完整 PLMN。

### Mobile Station International Subscriber Directory Number (MSISDN)；移动台国际用户目录号

存储在 SIM 卡中的用户电话号码（即主叫号码），以 E.164 格式表示，与 IMSI 一一对应但可更换。

### Modem；调制解调器

移动终端中负责蜂窝空口信号处理的硬件子系统及固件，承担调制解调、信道编解码、网络注册等基带功能，Radio 开关实际控制其射频上下电状态。

### Multimedia Messaging Service (MMS)；彩信

在移动网络上传输包含文本、图片、音频、视频等多媒体内容消息的业务，与纯文本 SMS 不同，采用基于 WAP/HTTP 的 PDU 封装并经 MMSC 存储转发。

### Multimedia Messaging Service Center (MMSC)；多媒体消息业务中心

MMS 网络中负责存储转发多媒体消息的核心网元，终端发送彩信时将 PDU 提交至此，由其向接收方下发通知，接收方再检索完整内容。

## N

### Network Identification (NID)；网络识别码

CDMA 网络中标识运营商网络区块的编号，与 SID 组合区分运营商不同子网络，是 CDMA 网络选择、漫游判断的关键参数。

### New Radio (NR)；新空口

3GPP R15 起定义的 5G 空口标准，工作于 Sub-6GHz 及毫米波频段，可接入 5GC 构成 SA 组网，也可锚定在 LTE 上以 ENDC 方式实现 NSA 组网。

### Next Generation Radio Access Network (NG-RAN)；下一代无线接入网

5G 系统的无线接入网架构，由 gNB 与 ng-eNB 组成，通过 NG 接口连接 5GC，是 SA 组网下 NR 空口的接入网基础。

### Non-Standalone (NSA)；非独立组网

5G NR 以 LTE 为锚点、控制面依赖 EPC 的部署模式，无需 5GC 即可提供 NR 高速数据，是 5G 商用初期的过渡方案，与 SA 相对。

### NR Cell Identity (NCI)；5G小区标识

5G NR 中全局唯一标识小区的 36 位编号，由 gNB ID 与 Cell ID 组成，是 NR 网络中定位和标识小区的核心参数，对应 2G/3G 的 CGI 与 LTE 的 ECGI。

## O

### Operating System Upgrade (OSU)；eUICC操作系统升级

对 eUICC 内置操作系统进行版本升级的过程，影响 eUICC 平台固件本身，区别于配置文件的下载与切换。

### Operator；运营商

提供移动通信网络服务的企业，拥有 PLMN 并发行 SIM 卡；Telephony Kit 中运营商信息以长/短名称、PLMN 码等形式呈现，并影响默认 APN 配置。

### Operator PLMN List (OPL)；运营商PLMN列表

存储在 SIM/eUICC 上的运营商自定义 PLMN 与地理区域映射表，用于网络选择时结合当前位置确定应显示的运营商名称（与 PNN 配合）。

## P

### Packet Switched (PS)；分组交换

蜂窝通信中以分组为单位按需共享信道资源承载数据业务的交换方式，与电路交换（CS）相对，LTE/NR 中所有业务均基于该方式。

### Personal Identification Number (PIN)；个人识别码

保护 SIM 卡不被未授权使用的本地密码，默认 4~8 位，连续错误达上限后需 PUK 解锁，是 SIM 卡安全体系的第一道防线。

### Personal Unblocking Key (PUK)；个人解锁码

PIN 被锁死后用于重置 PIN 的运营商级解锁码，错误次数达上限将永久锁卡需换卡，是 SIM 卡安全体系的二级解锁机制。

### Physical Cell Identifier (PCI)；物理小区标识

LTE/NR 物理层用于区分相邻小区的标识，LTE 范围 0~503、NR 范围 0~1007，由主/辅同步信号推导，是小区搜索、解调与切换的关键参数。

### PLMN Network Name (PNN)；PLMN网络名称

运营商在 SIM/eUICC 中维护的网络名称列表，与 OPL 配合根据当前驻留 PLMN 动态显示运营商名称。

### Profile；配置文件

eSIM 体系下驻留于 eUICC 的一组运营商订阅数据集合（含 IMSI、密钥、文件系统等），等效于一张虚拟 SIM 卡，同一 eUICC 上可多份共存但通常仅一个启用。

### Profile Policy Rule (PPR)；配置文件策略规则

由运营商下发并写入配置文件的策略，约束其禁用、删除等行为（如不可禁用、不可删除），违反时操作将被拒绝。

### Protocol Data Unit (PDU)；协议数据单元

短信/彩信在网络与终端间传输的协议层封装格式，含消息头（地址、协议标识、时间戳等）与用户数据，按消息类型区分头结构。

### Public Land Mobile Network (PLMN)；公用陆地移动网

由 MCC+MNC 唯一标识的移动运营商网络，是终端选网、漫游、注册的基本单位，每个 PLMN 对应特定运营商在特定国家的网络。

### Primary Scrambling Code (PSC)；主扰码

WCDMA 中区分小区的 512 个扰码之一，是终端识别相邻小区、进行软切换的关键参数，与 PCI 在 LTE 中的角色类似。

## R

### Radio Access Technology (RAT)；无线接入技术

终端接入移动网络所使用的无线空口技术规范，是区分不同代际和制式网络的核心维度，如 GSM、WCDMA、LTE、NR 各为不同 RAT。

### Removable User Identity Module (RUIM)；可移动用户身份模块

用于 CDMA 网络的可插拔用户识别卡，功能与 GSM 中的 SIM 对应，与 USIM、ISIM 等并列区分不同制式的用户身份模块。

### Replace Short Message；替换短信

3GPP TS 23.040 定义的一类特殊短信，用于替换终端中先前由同一发送方存储的同标识消息，避免重复存储，与普通短信及状态报告相区分。

### Roaming；漫游

终端在非归属运营商网络上使用蜂窝数据或语音服务的状态，需运营商间协议支持并通常产生额外费用；蜂窝数据漫游需单独开关控制，与蜂窝数据总开关独立。

## S

### Service Provider Name (SPN)；服务提供商名称

存储在 SIM 卡 EF_SPN 文件中的运营商服务名，用于终端状态栏等位置显示，区别于网络名（PNN），其显示规则由 SPN 显示条件控制。

### SGP.22；eUICC技术规范

GSMA SGP.22 规范，定义 eUICC 与 SM-DP+ 之间的远程配置文件管理协议（含认证、下载、安装、策略等流程），是 eSIM 互操作性的国际技术基线。

### Short Message Service (SMS)；短消息业务

在移动网络上传输有限长度文本或数据消息的电信业务，俗称“短信”，通过 SMSC 存储转发，单条容量受编码方式约束。

### Short Message Service Center (SMSC)；短消息服务中心

移动网络中负责短信存储转发的核心网元，终端发送短信时先提交至此，由其按目标地址寻址投递。

### SIM Application Toolkit；SIM应用工具包

3GPP/ETSI 定义的主动式命令机制，允许 SIM 卡主动与终端交互（下发菜单、刷新、呼叫控制等），终端通过信封命令上报事件、终端响应回应对主动指令。

### SIM Authentication；SIM卡鉴权

利用 SIM/eUICC 内置密钥与算法在终端与网络间完成身份验证的过程，支持 EAP-SIM、EAP-AKA 等类型，用于 WLAN/IMS 等接入场景借用 SIM 凭证完成认证。

### Single-Carrier Radio Transmission Technology (1XRTT)；单载波无线电传输技术

CDMA2000 1X 空口采用的无线传输技术，单载波提供话音与中低速分组数据业务，是 IS-95 向 EVDO 演进的中间代际制式，与 EVDO 分工承担话音与数据。

### Slot；卡槽

设备上用于插入 SIM 卡的物理或逻辑槽位，通过卡槽 ID（slotId）区分，多卡设备中卡槽 1 对应 ID 为 0、卡槽 2 对应 ID 为 1，用于定位操作作用于哪张卡。

### SMS Status Report；短信状态报告

SMSC 向终端返回的、告知发送方短信送达状态的特定格式短消息，与发送结果回调及送达报告回调协同构成短信发送的完整反馈链路。

### Stage模型

HarmonyOS 的应用开发模型，提供 UIAbility 与 ExtensionAbility 等组件类型，区别于早期 FA 模型，部分 Telephony 接口仅在此模型下可用。

### Standalone (SA)；独立组网

5G NR 直接接入 5GC 的完整部署模式，支持网络切片、超低时延等 5G 全部特性，是 5G 的最终目标架构，与 NSA 相比需完整 5GC 部署。

### Subscriber Identity Module (SIM)；用户身份模块

3GPP 体系中存储用户身份（IMSI）、鉴权密钥、电话簿等数据的可插拔智能卡，是接入移动网络的凭据载体，泛指包含 USIM、ISIM、RUIM 在内的所有形态。

### Subscription Manager Data Preparation Plus (SM-DP+)；订阅管理器数据准备服务器

GSMA 标准定义的、负责为 eUICC 准备并下发配置文件的运营商侧服务器，是 eSIM 远程配置的核心节点。

### Synchronized Multimedia Integration Language (SMIL)；同步多媒体集成语言

基于 XML 的标记语言，用于描述多媒体演示中各组成部分的时间编排与布局，在彩信中作为附件控制内容播放顺序与版式。

### System application；系统应用

HarmonyOS 中预置并具备系统级权限的应用类型，本 Kit 中部分接口所需权限仅系统应用可申请，普通应用无法获取。

### System Identification (SID)；系统识别码

CDMA 网络中标识运营商系统的编号，与 NID 共同确定 CDMA 终端的归属网络和漫游状态。

### System interface；系统接口

仅系统应用可调用的 API，受系统权限管控，普通应用调用会返回 202 错误码，本 Kit 中以 -sys 后缀文件单独提供，是公开接口的超集。

### SystemCapability；系统能力

HarmonyOS 中标识设备所支持特性/能力的机制，以“SystemCapability.子系统.能力”形式声明，接口通过该标签标注所属能力，用于跨设备能力校验与运行时降级。

## T

### Tag-Length-Value (TLV)；标签-长度-值

智能卡（含 SIM/eUICC）数据交换中标准的编码格式，每条数据由标签、长度、值三段组成可嵌套，便于卡侧按 BER-TLV 规则解析。

### Telephony Kit；电话服务套件

HarmonyOS 提供电话能力的开发套件，封装通话、蜂窝数据、网络搜索、SIM/eSIM 卡、短信、observer 等模块，是访问 Telephony 子系统功能的统一入口。

### Terminal Response；终端响应

SIM 应用工具包（USAT）中终端对 SIM 卡主动命令的应答数据，包含命令执行状态与可选数据回传，与信封命令共同构成 ME↔UICC 应用层交互闭环。

### Tianjitong；天际通

HarmonyOS 设备提供的境外数据漫游服务，通过虚拟 SIM 卡为用户提供境外蜂窝数据接入，在默认移动数据场景下占用特殊 slotId，区别于普通物理 SIM 卡。

### Time Division Multiplexing (TDM)；时分复用

DSDS V5_TDM 模式下两卡共享同一射频通道的复用方式，通过时间片切换在两卡间交替收发，使双卡均可待机但同一时刻仅一卡可业务。

### Time Division-Synchronous Code Division Multiple Access (TD-SCDMA)；时分同步码分多址

3GPP 定义的 3G TDD 空口标准，采用智能天线和同步 CDMA 技术，主要在中国部署，是中国自主提出的第三代移动通信国际标准。

### TP-Reply-Path；TP回复路径

SMS TPDU 中指示回复消息是否经由原发送方所用 SMSC 路由的协议字段，为 true 时接收方回复将使用原短信的 SMSC 地址而非默认 SMSC。

### Tracking Area Code (TAC)；跟踪区域代码

LTE/NR 中标识跟踪区的编号，跟踪区是 PS 域移动性管理单位，替代 CS 域的 LAC，终端跨跟踪区移动时触发跟踪区更新。

## U

### UIAbility

Stage 模型中带 UI 界面的应用组件类型，是应用与用户交互的入口；本 Kit 中涉及界面跳转的接口（如 makeCall）需在 UIAbility 实例中调用，区别于无界面的 ExtensionAbility。

### Universal Character Set 2 (UCS-2)；通用双字节字符集

短信中用于编码非 GSM 默认字母表字符（如中文）的 16 位编码方案，使用时单条 SMS 容量从 160 字符（7 位）降为 70 字符。

### Universal Mobile Telecommunications System (UMTS)；通用移动通信系统

3GPP 制定的第三代移动通信（3G）系统，其短信协议与 GSM、LTE 同属 3GPP（“3gpp”）协议族，PDU 结构与编码方式一致，与 3GPP2（CDMA）短信协议相区分。

### Universal Subscriber Identity Module (USIM)；通用用户身份模块

3G/4G/5G 网络使用的、兼容 SIM 但增强安全性的用户身份模块，支持更长密钥与双向认证，是 EAP-AKA、IMS 等业务的能力基础。

### User Agent (UA)；用户代理

MMS 客户端在与 MMSC 交互时标识自身类型与能力的字符串，类似 HTTP 的 User-Agent 头，MMSC 可据此返回适配的内容格式。

### User Agent Profile (UAProf)；用户代理描述

描述 MMS 终端硬件能力（屏幕尺寸、支持媒体类型等）的描述文件 URL，MMSC 据此对彩信内容进行转码适配，与 UA 配合使用。

### Ut；补充业务接口

基于 HTTP/XCAP 的补充业务（呼叫转移、呼叫等待等）配置接口，区别于传统 SS 信令，其连接与下发受运营商支持情况影响。

### UTRA Absolute Radio Frequency Channel Number (UARFCN)；UTRA绝对无线频率信道号

WCDMA/TD-SCDMA 中标识 UTRA 载波频点的编号，以 200kHz 为单位换算绝对频率，用于 3G 网络频点配置与测量上报。

## V

### vCard；电子名片

表示联系人信息（姓名、电话、地址、URL、照片等）的文件格式标准，HarmonyOS VCard 模块支持将其导入联系人数据库或反向导出，支持 2.1/3.0/4.0 版本。

### vCard File (VCF)；vCard文件

符合 vCard 标准的联系人信息文件（扩展名 .vcf），以纯文本键值对组织联系人字段，用于导入导出操作。

### Voice over LTE (VoLTE)；LTE语音

基于 IMS 架构在 LTE 数据承载上提供的语音业务，区别于传统 CS 域语音，其支持与开关受运营商配置项控制。

## W

### WAP Push；WAP推送

基于 WAP 协议向终端主动推送内容（URL、配置参数、彩信通知等）的机制，通常以数据短信（端口寻址）为承载；彩信流程中 MMSC 通过其向接收方下发通知。

### Wideband Code Division Multiple Access (WCDMA)；宽带码分多址

3GPP 定义的 3G FDD 空口标准，使用 5MHz 宽带 DS-CDMA 接入，可同时承载 CS 话音与 HSPA 高速分组数据业务，是欧洲及全球多数运营商的 3G 主流制式。
