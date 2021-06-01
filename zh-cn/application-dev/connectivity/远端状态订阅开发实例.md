# 远端状态订阅开发实例<a name="ZH-CN_TOPIC_0000001104030756"></a>

IPC/RPC提供对远端Stub对象状态的订阅机制， 在远端Stub对象死亡时，可触发死亡通知告诉本地Proxy对象。这种状态通知订阅并不会自动附加在每个本地Proxy对象上，需要调用特定接口完成，当不再需要订阅时也需要调用特定接口取消。使用这种订阅机制的用户，需要实现死亡通知接口DeathRecipient并实现onRemoteDied方法，清理资源，该方法会在远端Stub对象所在进程死亡，或所在设备离开组网时被回调。值得注意的是，调用这些接口有一定的顺序。首先，必然需要Proxy订阅Stub死亡通知，若在订阅期间未发生Stub死亡，则可在不再需要时取消订阅；若在订阅期间发生Stub死亡，则会自动触发Proxy自定义的后续操作，也无需再手动取消订阅。

RPC目前不提供匿名Stub对象的死亡通知，即只有向SAMgr注册过的服务才能被订阅死亡通知。IPC则支持匿名对象的死亡通知。

**Native侧接口**

依次为添加对远端Stub对象状态订阅的接口，取消订阅的接口，及感知到远端Stub对象死亡而进行本地操作的接口：

```
bool AddDeathRecipient(const sptr<DeathRecipient> &recipient);
bool RemoveDeathRecipient(const sptr<DeathRecipient> &recipient);
void OnRemoteDied(const wptr<IRemoteObject> &object);
```

参考代码

```
class TestDeathRecipient : public IRemoteObject::DeathRecipient {
public:
    virtual void OnRemoteDied(const wptr<IRemoteObject>& remoteObject);
}
sptr<IRemoteObject::DeathRecipient> deathRecipient (new TestDeathRecipient()); // 构造一个死亡通知对象
bool result = proxy->AddDeathRecipient(deathRecipient); // 注册死亡通知
result = proxy->RemoveDeathRecipient(deathRecipient); // 移除死亡通知
```

