# 剪贴板错误码

## 12900001 索引超过范围

### 错误信息

The index is out of range.

### 错误描述

例如调用getRecord时，index超出当前pasteData中所存记录数

### 可能原因

剪贴板getRecord时传入index错误。

### 处理步骤

1. 重新输入正确的index，以此获取记录。

## 12900002 Record数量超过最大限制

### 错误信息

The number of record exceeds the maximum limit

### 错误描述

当调用addRecord时，当前pasteData记录数已到达最大记录数。

### 可能原因

1. 未对当前PasteData记录数进行判断。

### 处理步骤

1. 确认当前PasteData记录数是否已达到最大记录数。

## 12900003 另外一个复制或粘贴正在进行

### 错误信息

Another copy or paste is in progress

### 错误描述

上次调用setPasteData或getPasteData动作还未结束，再次调用，会报此错误码。。

### 可能原因

1. setPasteData或getPasteData时，数据量较大，拷贝较慢，再次调用，则会出错。

### 处理步骤

1. 调用异步接口setPasteData或者getPasteData时，确保函数调用结束，在进行后续操作。

## 12900004 禁止复制

### 错误信息

Replication is prohibited

### 错误描述

剪贴板内容禁止复制。

### 可能原因

1. 某些只读文档数据，禁止在此应用内复制。

### 处理步骤

1. 开发者无法调用setPasteData对此类文档复制