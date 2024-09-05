# Developing a Long List with Lazy Loading

For the **List**, **Grid**, **WaterFlow**, and **Swiper** components, the [NodeAdapter](../reference/apis-arkui/_ark_u_i___native_module.md#arkui_nodeadapterhandle) object is provided as an alternative to the ArkTS **LazyForEach** feature for on-demand child component generation. The specific attribute enumeration values are as follows:

- **List**: **NODE_LIST_NODE_ADAPTER**
- **Grid**: **NODE_GRID_NODE_ADAPTER**
- **WaterFlow**: **NODE_WATER_FLOW_NODE_ADAPTER**
- **Swiper**: **NODE_SWIPER_NODE_ADAPTER**


Key specifications of **NodeAdapter** include:


- Nodes with **NodeAdapter** set do not support direct child addition APIs like **addChild**. Child components are managed entirely by **NodeAdapter**. If a parent component already has child nodes, setting **NodeAdapter** will fail and return an error code.

- **NodeAdapter** uses events to notify you to generate components on demand. You must register an [event listener](../reference/apis-arkui/_ark_u_i___native_module.md#oh_arkui_nodeadapter_registereventreceiver) and handle logic within listener events, which are defined by [ArkUI_NodeAdapterEventType](../reference/apis-arkui/_ark_u_i___native_module.md#arkui_nodeadaptereventtype). **NodeAdapter** does not automatically release off-screen component objects; you must manage object release or caching during the [NODE_ADAPTER_EVENT_ON_REMOVE_NODE_FROM_ADAPTER](../reference/apis-arkui/_ark_u_i___native_module.md#arkui_nodeadaptereventtype) event.