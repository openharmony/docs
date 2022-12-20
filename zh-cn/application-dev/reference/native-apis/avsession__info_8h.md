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
| [OHOS::AVSession::SessionListener](_o_h_o_s_1_1_a_v_session_1_1_session_listener.md) | class<br/>定义与AVSession相关监听器的类的实现。  | 
| [OHOS::AVSession::AVSessionCallback](_o_h_o_s_1_1_a_v_session_1_1_a_v_session_callback.md) | class<br/>定义AVSession回调类的实现  | 
| [OHOS::AVSession::AVControllerCallback](_h_o_s_1_1_a_v_session_1_1_a_v_controller_callback.md) | class<br/>定义控制器相关回调操作的类的实现。  | 
| [OHOS::AVSession::SessionToken](_o_h_o_s_1_1_a_v_session_1_1_session_token.md) | struct<br/>会话令牌的信息。  | 


### 类型定义

  | 名称 | 描述 | 
| -------- | -------- |
| [OHOS::AVSession::DeathCallback](#deathcallback) = std::function&lt; void()&gt; | using | 


### 枚举

  | 名称 | 描述 | 
| -------- | -------- |
| [OHOS::AVSession::SessionDataCategory](#sessiondatacategory) {<br/> **OHOS::AVSession::SESSION_DATA_CATEGORY_INVALID** = -1, **OHOS::AVSession::SESSION_DATA_META** = 0,  **OHOS::AVSession::SESSION_DATA_PLAYBACK_STATE** = 1, **OHOS::AVSession::SESSION_DATA_CONTROL_COMMAND** = 2, **OHOS::AVSession::SESSION_DATA_CATEGORY_MAX** = 3<br/>} | 会话元数据处理标识  | 


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
| SESSION_DATA_CATEGORY_INVALID  | 无效类型，内部用于类型是否有效 | 
| SESSION_DATA_META  | 会话元数据 | 
| SESSION_DATA_PLAYBACK_STATE  | 会话播放状态 | 
| SESSION_DATA_CONTROL_COMMAND  | 会话控制命令 | 
| SESSION_DATA_CATEGORY_MAX  | 会话数据类型的数量 | 
