# Building a Custom Component


The ArkUI development framework provides capabilities for creating custom UI components through NDK APIs, including custom measurement, layout, and drawing. You can integrate into ArkUI's layout and rendering process by registering custom callback events using the [registerNodeCustomEvent](../reference/apis-arkui/_ark_u_i___native_node_a_p_i__1.md#registernodecustomevent) function and adding custom event listeners for components with the [addNodeCustomEventReceiver](../reference/apis-arkui/_ark_u_i___native_node_a_p_i__1.md#addnodecustomeventreceiver) function. The logic for custom measurement, layout, and drawing is handled within the callback functions of these listeners.

   
