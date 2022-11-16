# NavRouter

导航组件，默认提供点击响应处理，不需要开发者自定义点击事件逻辑。

> **说明：**
>
> 该组件从API Version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 子组件

必须包含两个子组件，其中第二个子组件必须为[NavDestination](ts-basic-components-navdestination.md)。

## 接口

NavRouter()


## 事件

| 名称                                       | 功能描述                                     |
| ---------------------------------------- | ---------------------------------------- |
| onStateChange(callback: (isActivated: boolean) => void) | 组件激活状态切换时触发该回调。返回值isActivated为true时表示激活，为false时表示未激活。</br> **说明：**用户点击NavRouter，激活NavRouter，加载对应的NavDestination子组件时，回调onStateChange(true)；NavRouter对应的NavDestination子组件不再显示时，回调onStateChange(false)。  |
