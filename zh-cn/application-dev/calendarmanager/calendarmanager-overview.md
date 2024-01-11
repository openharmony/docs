# Calendar Kit简介

## Calendar Kit开发概述

日历：用于记载日期、节日，重要事件的工具。

## Calendar Kit简介

Calendar Kit提供日历与日程管理能力，包括日历的获取和日程的创建能力。日历管理器CalendarManager用于管理日历Calendar。日历Calendar主要包含帐户信息CalendarAccount和配置信息CalendarConfig。日历Calendar与日程Event属于一对多关系，一个Calendar可以有多个Event，一个Event只属于一个Calendar。

## 运作机制

Calendar Kit为用户提供了一系列接口来获取日历账户，并使用特定的接口向日历账户中写入日程。如果写入的日程带有提醒时间则系统会在时间到达时向用户发送提醒。

## 约束与限制

- Calendar Kit需要用户手动授权获取读取、写入日历日程的权限。

- Calendar Kit仅支持stage模型。

- Calendar Kit从api11开始支持