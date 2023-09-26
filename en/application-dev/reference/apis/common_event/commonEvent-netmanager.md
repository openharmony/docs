# Common Events of the Network Management Subsystem
This document lists the common system events provided by the network management subsystem to applications. Applications can use [APIs](../js-apis-commonEventManager.md) to subscribe to common system events.


## COMMON_EVENT_CONNECTIVITY_CHANGE<sup>10+<sup>

Indicates that the network connection state has changed.

- Value: usual.event.CONNECTIVITY_CHANGE
- Required subscriber permissions: none

When the (Ethernet, Wi-Fi, or cellular) network connection state changes (to disconnected, connecting, or connected), the event notification service is triggered to publish this event.

## COMMON_EVENT_AIRPLANE_MODE_CHANGED<sup>10+<sup>

Indicates that the airplane mode state has changed.

- Value: usual.event.AIRPLANE_MODE
- Required subscriber permissions: none

When the airplane mode is set, the event notification service is triggered to publish this event.

## COMMON_EVENT_HTTP_PROXY_CHANGE<sup>10+<sup>

Indicates that the HTTP proxy configuration has changed.

- Value: usual.event.HTTP_PROXY_CHANGE
- Required subscriber permissions: none

When the configuration of the global or network-specific (such as Ethernet and Wi-Fi) HTTP proxy changes, the event notification service is triggered to publish this event.

## COMMON_EVENT_NET_QUOTA_WARNING<sup>10+<sup>

Indicates that the network data usage has reached the alarm threshold.

- Value: usual.event.QUOTA_WARNING
- Required subscriber permissions: none

When the network data usage reaches 80% of the limit, the event notification service is triggered to publish this event.

## COMMON_EVENT_NET_QUOTA_LIMIT_REMINDED<sup>10+<sup>

Indicates that the network data usage has reached the upper limit, and network access is still available.

- Value: usual.event.NET_QUOTA_LIMIT_REMINDED
- Required subscriber permissions: none

When the network data usage reaches the upper limit and the user chooses to continue to use the network, the event notification service is triggered to publish this event.

## COMMON_EVENT_NET_QUOTA_LIMIT<sup>10+<sup>

Indicates that the network data usage has reached the upper limit, and network access becomes unavailable.

- Value: usual.event.NET_QUOTA_LIMIT
- Required subscriber permissions: none

When the network data usage reaches the upper limit and continuing to use the network is not allowed, the event notification service is triggered to publish this event.
