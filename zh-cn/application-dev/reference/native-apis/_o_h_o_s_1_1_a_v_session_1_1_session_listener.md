# OHOS::AVSession::SessionListener


## 概述

定义与AVSession相关监听器的类的实现。

**Since:**
9
**Version:**
1.0

## 汇总


### Public 成员函数

  | 名称 | 描述 | 
| -------- | -------- |
| [OnSessionCreate](#onsessioncreate)&nbsp;(const&nbsp;[AVSessionDescriptor](o_h_o_s_1_1_a_v_session_1_1_a_v_session_descriptor.md)&nbsp;&amp;descriptor)=0 | 创建AVSession会话的抽象的接口回调方法。&nbsp; | 
| [OnSessionRelease](#onsessionrelease)&nbsp;(const&nbsp;[AVSessionDescriptor](o_h_o_s_1_1_a_v_session_1_1_a_v_session_descriptor.md)&nbsp;&amp;descriptor)=0 | 释放AVSession会话的抽象的接口回调方法。&nbsp; | 
| [OnTopSessionChange](#ontopsessionchange)&nbsp;(const&nbsp;[AVSessionDescriptor](o_h_o_s_1_1_a_v_session_1_1_a_v_session_descriptor.md)&nbsp;&amp;descriptor)=0 | AVSession的TOP会话发生变化的抽象的接口回调方法。&nbsp; | 
| [~SessionListener](#sessionlistener)&nbsp;()=default | SessionListener的默认的析构函数。&nbsp; | 


## 构造及析构函数说明


### ~SessionListener()

  
```
virtual OHOS::AVSession::SessionListener::~SessionListener ()
```
**描述:**
SessionListener的默认的析构函数。


## 成员函数说明


### OnSessionCreate()

  
```
virtual void OHOS::AVSession::SessionListener::OnSessionCreate (const AVSessionDescriptor & descriptor)
```
**描述:**
创建AVSession会话的抽象的接口回调方法。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| descriptor | AVSession的会话描述对象，类型为[AVSessionDescriptor](o_h_o_s_1_1_a_v_session_1_1_a_v_session_descriptor.md)。&nbsp; | 

**参见:**

[OnSessionRelease](#onsessionrelease)


### OnSessionRelease()

  
```
virtual void OHOS::AVSession::SessionListener::OnSessionRelease (const AVSessionDescriptor & descriptor)
```
**描述:**
释放AVSession会话的抽象的接口回调方法。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| descriptor | AVSession的会话描述对象，类型为[AVSessionDescriptor](o_h_o_s_1_1_a_v_session_1_1_a_v_session_descriptor.md)。&nbsp; | 

**参见:**

[OnSessionCreate](#onsessioncreate)


### OnTopSessionChange()

  
```
virtual void OHOS::AVSession::SessionListener::OnTopSessionChange (const AVSessionDescriptor & descriptor)
```
**描述:**
AVSession的TOP会话发生变化的抽象的接口回调方法。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| descriptor | AVSession的会话描述对象，类型为[AVSessionDescriptor](o_h_o_s_1_1_a_v_session_1_1_a_v_session_descriptor.md)。&nbsp; | 

<!--no_check-->