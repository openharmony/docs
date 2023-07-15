# 软总线子系统ChangeLog

## cl.softbus.1 IPC接口中unregisterDeathRecipient接口返回值变更，更改为void。

unregisterDeathRecipient(recipient: DeathRecipient, flags: number)方法返回值为boolean，更正为void。

**变更影响**

该unregisterDeathRecipient接口如果需要继续使用，建议优先使用removeDeathRecipient(recipient: DeathRecipient, flags: number): boolean方法。

**关键的接口/组件变更**

- 变更前：

```js
    unregisterDeathRecipient(recipient: DeathRecipient, flags: number): boolean
```

- 变更后：

```js
    unregisterDeathRecipient(recipient: DeathRecipient, flags: number): void
```

**适配指导**

该unregisterDeathRecipient接口如果需要继续使用，建议优先使用removeDeathRecipient(recipient: DeathRecipient, flags: number): boolean方法。