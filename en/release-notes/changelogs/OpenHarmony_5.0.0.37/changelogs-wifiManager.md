# Wi-Fi Changelog

## cl.arkui.1 getLinkedInfo Behavior Change

**Access Level**

Public API

**Reason for Change**

The change is made to resolve security issues. Before the change, with only the GET_WIFI_INFO permission, the application can obtain the BSSID of the hotspot connected by the user, and further determines the location of the user. This poses security risks.

**Change Impact**

This change is a non-compatible change.

Before the change: 

With the GET_WIFI_INFO permission only, the application can obtain the BSSID of the hotspot connected by the user.

After the change: 

To obtain the BSSID of the connected hotspot, the application must have the GET_WIFI_INFO and GET_WIFI_PEERS_MAC permissions. If the application does not have the GET_WIFI_PEERS_MAC permission, the returned BSSID is empty.

**Start API Level**

API 12

**Change Since**

OpenHarmony 5.0.0.37

**Key API/Component Changes**

getLinkedInfo/wifi module

**Adaptation Guide**

No adaptation is required. However, you need to check whether the changed behavior affects the overall application logic.
