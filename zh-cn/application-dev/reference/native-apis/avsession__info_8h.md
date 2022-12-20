# avsession_info.h


## 概述

定义了与avsession相关的监听器以及回调功能的实现。

**Since:**
9
**Version:**
1.0
**相关模块:**

[Avsession](avsession.md)


## 汇总


### 结构体

  | 名称 | 描述 | 
| -------- | -------- |
| [OHOS::AVSession::SessionListener](_o_h_o_s_1_1_a_v_session_1_1_session_listener.md) | class<br/>定义与AVSession相关监听器的类的实现。&nbsp; | 
| [OHOS::AVSession::AVSessionCallback](_o_h_o_s_1_1_a_v_session_1_1_a_v_session_callback.md) | class<br/>定义AVSession回调类的实现&nbsp; | 
| [OHOS::AVSession::AVControllerCallback](_h_o_s_1_1_a_v_session_1_1_a_v_controller_callback.md) | class<br/>定义控制器相关回调操作的类的实现。&nbsp; | 
| [OHOS::AVSession::SessionToken](_o_h_o_s_1_1_a_v_session_1_1_session_token.md) | struct<br/>会话令牌的信息。&nbsp; | 


### 类型定义

  | 名称 | 描述 | 
| -------- | -------- |
| [OHOS::AVSession::DeathCallback](#deathcallback)&nbsp;=&nbsp;std::function&lt;&nbsp;void()&gt; | using | 


### 枚举

  | 名称 | 描述 | 
| -------- | -------- |
| [OHOS::AVSession::SessionDataCategory](#sessiondatacategory)&nbsp;{<br/>[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001423775882.xml#xref1378898340182348,link:zh-cn_topic_0000001423775882.xml#af4f7fda77f9a1e4036911a6471f66a94a21750f709a53526691ca2eb109fa9a38](#af4f7fda77f9a1e4036911a6471f66a94a21750f709a53526691ca2eb109fa9a38)&nbsp;=&nbsp;-1,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001423775882.xml#xref1175489743182348,link:zh-cn_topic_0000001423775882.xml#af4f7fda77f9a1e4036911a6471f66a94ad7439aa6d8972182670a565f8761b118](#af4f7fda77f9a1e4036911a6471f66a94ad7439aa6d8972182670a565f8761b118)&nbsp;=&nbsp;0,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001423775882.xml#xref27428182182348,link:zh-cn_topic_0000001423775882.xml#af4f7fda77f9a1e4036911a6471f66a94aed15c5d580452ab6a93d770d09973a7f](#af4f7fda77f9a1e4036911a6471f66a94aed15c5d580452ab6a93d770d09973a7f)&nbsp;=&nbsp;1,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001423775882.xml#xref1899079755182348,link:zh-cn_topic_0000001423775882.xml#af4f7fda77f9a1e4036911a6471f66a94a91326fb49a2fed524dc25cf1e3fa47be](#af4f7fda77f9a1e4036911a6471f66a94a91326fb49a2fed524dc25cf1e3fa47be)&nbsp;=&nbsp;2,<br/>[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001423775882.xml#xref1569465139182348,link:zh-cn_topic_0000001423775882.xml#af4f7fda77f9a1e4036911a6471f66a94ac8da34449a638e3051da12298a9946e2](#af4f7fda77f9a1e4036911a6471f66a94ac8da34449a638e3051da12298a9946e2)&nbsp;=&nbsp;3<br/>} | 会话元数据处理标识&nbsp; | 


## 类型定义说明


### DeathCallback

  
```
using OHOS::AVSession::DeathCallback = typedef std::function<void()>
```
**描述:**
AVSession死亡回调


## 枚举类型说明


### SessionDataCategory

  
```
enum OHOS::AVSession::SessionDataCategory
```
**描述:**
会话元数据处理标识

  | 枚举值 | 描述 | 
| -------- | -------- |
| SESSION_DATA_CATEGORY_INVALID&nbsp; | 无效类型，内部用于类型是否有效 | 
| SESSION_DATA_META&nbsp; | 会话元数据 | 
| SESSION_DATA_PLAYBACK_STATE&nbsp; | 会话播放状态 | 
| SESSION_DATA_CONTROL_COMMAND&nbsp; | 会话控制命令 | 
| SESSION_DATA_CATEGORY_MAX&nbsp; | 会话数据类型的数量 | 
