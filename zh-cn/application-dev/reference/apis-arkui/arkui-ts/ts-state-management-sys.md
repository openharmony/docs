# 应用级变量的状态管理（系统接口）
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zzq212050299-->
<!--SE: @s10021109-->
<!--TSE: @TerryTsao-->


状态管理模块提供了应用程序的数据存储能力、持久化数据管理能力、UIAbility数据存储能力和应用程序需要的环境状态。


>**说明：**
>
>本模块首批接口从API version 7开始支持，后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
>当前页面仅包含本模块的系统接口，其他公开接口参见[应用级变量的状态管理](./ts-state-management.md)。

## SubscribedAbstractProperty\<T\>

**卡片能力：** 从API version 9开始，支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### subscribers\_

protected subscribers_: Set\<number\>;

订阅者集合。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

|类型   |说明       |
|-----------|--------------|
|Set\<number\>  |返回Set集合。 |

### id\_

private id_;

私有成员变量id_。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### info\_

private info\_\?;

变量信息。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### constructor

constructor(subscribeMe?: IPropertySubscriber,info?: string,);

构造函数。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

|参数名   |类型   |必填   |说明             |
|---------|-----------|------------|--------------|
|subscribeMe   |[IPropertySubscriber](#ipropertysubscriber)   |否   |变量属性。    |
|info   |string   |否   |变量信息。   |

### id

id(): number;

获取id时调用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

|类型   |说明       |
|-----------|--------------|
|number  |返回id。 |

### createTwoWaySync

createTwoWaySync(subscribeMe?: IPropertySubscriber, info?: string): SyncedPropertyTwoWay\<T\>;

创建双向同步时调用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

|参数名   |类型   |必填   |说明             |
|---------|-----------|------------|--------------|
|subscribeMe   |[IPropertySubscriber](#ipropertysubscriber)   |否   |变量属性。    |
|info   |string   |否   |变量信息。   |

**返回值：**

|类型   |说明       |
|-----------|--------------|
|[SyncedPropertyTwoWay\<T\>](#syncedpropertytwowayt)  |返回双向同步属性。 |

### createOneWaySync

createOneWaySync(subscribeMe?: IPropertySubscriber, info?: string): SyncedPropertyOneWay\<T\>;

创建单向同步时调用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

|参数名   |类型   |必填   |说明             |
|---------|-----------|------------|--------------|
|subscribeMe   |[IPropertySubscriber](#ipropertysubscriber)   |否   |变量属性。    |
|info   |string   |否   |变量信息。   |

**返回值：**

|类型   |说明       |
|-----------|--------------|
|[SyncedPropertyOneWay\<T\>](#syncedpropertytwowayt)  |返回单向同步属性。 |

### unlinkSuscriber

unlinkSuscriber(subscriberId: number): void;

变量解除订阅时调用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

|参数名   |类型   |必填   |说明             |
|---------|-----------|------------|--------------|
|subscriberId   |number   |是   |变量id。    |

### notifyHasChanged

protected notifyHasChanged(newValue: T): void;

通知变化时调用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

|参数名   |类型   |必填   |说明             |
|---------|-----------|------------|--------------|
|newValue   |T   |是   |更改后的新值。    |

### notifyPropertyRead

protected notifyPropertyRead(): void;

通知读取时调用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### numberOfSubscrbers

numberOfSubscrbers(): number;

获取订阅者数量时调用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

|类型   |说明       |
|-----------|--------------|
|number  |返回订阅者数量。 |

## IPropertySubscriber

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### id

id(): number;

获取id时调用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

|类型   |说明       |
|-----------|--------------|
|number  |返回变量id。 |

### aboutToBeDeleted

aboutToBeDeleted(owningView?: IPropertySubscriber): void;

销毁时调用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

|参数名   |类型   |必填   |说明             |
|---------|-----------|------------|--------------|
|owningView   |[IPropertySubscriber](#ipropertysubscriber)   |否   |所在自定义组件。    |

## SyncedPropertyTwoWay\<T\>

继承自[SubscribedAbstractProperty\<T\>](#subscribedabstractpropertyt)。用来定义变量状态的值。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### source\_

private source_;

双向同步属性的数据源。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### constructor

constructor(source: SubscribedAbstractProperty\<T\>, subscribeMe?: IPropertySubscriber, info?: string);

构造函数参数。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

|参数名   |类型   |必填   |说明             |
|---------|-----------|------------|--------------|
|source   |[SubscribedAbstractProperty\<T\>](#subscribedabstractpropertyt)   |是   |双向同步属性的数据源。    |
|subscribeMe   |[IPropertySubscriber](#ipropertysubscriber)   |否   |订阅者。   |
|info  |string   |否   |订阅者信息。   |

### aboutToBeDeleted

aboutToBeDeleted(unsubscribeMe?: IPropertySubscriber): void;

销毁时调用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

|参数名   |类型   |必填   |说明             |
|---------|-----------|------------|--------------|
|unsubscribeMe   |[IPropertySubscriber](#ipropertysubscriber)   |否   |被取消的订阅者。    |

### hasChanged

hasChanged(newValue: T): void;

变化时调用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

|参数名   |类型   |必填   |说明   |
|---------|-----------|------------|--------------|
|newValue   |T   |是   |T类型实例。     |

### get

get(): T;

获取数据时调用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

|类型   |说明     |
|------|------------|
|T   |T类型实例。    |

### set

set(newValue: T): void;

赋值时调用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

|参数名   |类型   |必填   |说明             |
|---------|-----------|------------|--------------|
|newValue   |T   |是   |T类型实例。    |

## SyncedPropertyOneWay\<T\>

继承自[SubscribedAbstractProperty\<T\>](#subscribedabstractpropertyt)。用来定义父组件的状态值。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### wrappedValue\_

private wrappedValue_;

单向绑定时的值。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### source\_

private source_;

双向同步属性的数据源。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### constructor

constructor(source: SubscribedAbstractProperty\<T\>, subscribeMe?: IPropertySubscriber, info?: string);

构造函数参数。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

|参数名   |类型   |必填   |说明             |
|---------|-----------|------------|--------------|
|source   |[SubscribedAbstractProperty\<T\>](#subscribedabstractpropertyt)   |是   |单向同步属性的数据源。    |
|subscribeMe   |[IPropertySubscriber](#ipropertysubscriber)   |否   |订阅者。   |
|info  |string   |否   |订阅者信息。   |

### aboutToBeDeleted

aboutToBeDeleted(unsubscribeMe?: IPropertySubscriber): void;

销毁时调用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

|参数名   |类型   |必填   |说明             |
|---------|-----------|------------|--------------|
|unsubscribeMe   |[IPropertySubscriber](#ipropertysubscriber)   |否   |被取消的订阅者。    |

### hasChanged

hasChanged(newValue: T): void;

变化时调用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

|参数名   |类型   |必填   |说明   |
|---------|-----------|------------|--------------|
|newValue   |T   |是   |T类型实例。     |

### get

get(): T;

获取数据源时调用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

|类型   |说明     |
|------|------------|
|T   |T类型实例。    |

### set

set(newValue: T): void;

赋值时调用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

|参数名   |类型   |必填   |说明             |
|---------|-----------|------------|--------------|
|newValue   |T   |是   |T类型实例。    |

## ISinglePropertyChangeSubscriber\<T\>

继承自[IPropertySubscriber](#ipropertysubscriber)。用来定义变量。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### hasChanged

hasChanged(newValue: T): void;

变化时调用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

|参数名   |类型   |必填   |说明             |
|---------|-----------|------------|--------------|
|newValue   |T   |是   |T类型实例。    |

## SubscribaleAbstract

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### owningProperties\_

private owningProperties_: Set\<number\>;

返回所持有的属性。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

|类型   |说明     |
|------|------------|
|Set\<number\>   |返回Set集合。    |

### constructor

constructor();

构造函数。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### notifyPropertyHasChanged

protected notifyPropertyHasChanged(propName: string, newValue: any): void;

当通知属性更改时调用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

|参数名   |类型   |必填   |说明             |
|---------|-----------|------------|--------------|
|propName   |string   |是   |属性名称。    |
|newValue   |any   |否   |更改的新值。   |

### addOwningProperty

public addOwningProperty(subscriber: IPropertySubscriber): void;

添加持有的属性。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

|参数名   |类型   |必填   |说明             |
|---------|-----------|------------|--------------|
|subscriber   |[IPropertySubscriber](#ipropertysubscriber)   |是   |订阅者。    |

### removeOwningProperty

public removeOwningProperty(property: IPropertySubscriber): void;

删除已拥有的属性时调用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

|参数名   |类型   |必填   |说明             |
|---------|-----------|------------|--------------|
|property   |[IPropertySubscriber](#ipropertysubscriber)   |是   |要删除的属性。    |

### removeOwningPropertyById

public removeOwningPropertyById(subscriberId: number): void;

使用id删除已拥有的属性时调用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

|参数名   |类型   |必填   |说明             |
|---------|-----------|------------|--------------|
|subscriberId   |number   |是   |要删除的属性id。    |

## Environment

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### constructor

constructor();

构造函数。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

## PersistentStorage

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### constructor

constructor(appStorage: AppStorage, storage: Storage);

构造函数参数。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

|参数名   |类型   |必填   |说明             |
|---------|-----------|------------|--------------|
|appStorage   |AppStorage   |是   |应用存储。    |
|storage   |Storage   |是   |存储。    |

## appStorage

declare const appStorage: AppStorage;

应用存储。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

|类型    |说明          |
|----------|------------|
|AppStorage   |应用存储。  |