# Contact Subsystem Changelog

## **Access Level**

Public

## Reason for the Change

Due to historical reasons, some enum constant values defined in the contact API reference are different from those actually used by the application.

## Change Impacts

This change is a non-compatible change.

## **Change Since**

OpenHarmony SDK4.1.3.1

## Adaptation Guide

If you have used the enum values of the attributes described in this section, you need to change them to the enum constants defined in the SDK. You are not advised to directly use these enum values.

## Mailbox Attribute

Custom mailbox type. The value of **CUSTOM_LABEL** is changed from 10000 to 0.

## Event Attribute

Custom event. The value of **CUSTOM_LABEL** is changed from 10000 to 0.

## IM Attribute

Custom IM. The value of **CUSTOM_LABEL** is changed from 10000 to -1.

AIM. The value of **IM_AIM** is changed from 1 to 0.

MSN IM. The value of **IM_MSN** is changed from 2 to 1.

YAHOO IM. The value of **IM_YAHOO** is changed from 3 to 2.

SKYPE IM. The value of **IM_SKYPE** is changed from 4 to 3.

QQ type. The value of **IM_QQ** is changed from 5 to 4.

ICQ IM. The value of **IM_ICQ** is changed from 7 to 6.

JABBER IM. The value of **IM_JABBER** is changed from 8 to 7.

## Phone Number Attribute

Custom phone number. The value of **CUSTOM_LABEL** is changed from 10000 to 0.

Home phone number. The value of **NUM_HOME** is changed from 2 to 1.

Mobile phone number. The value of **NUM_MOBILE** is changed from 1 to 2.

## Address Attribute

Custom mailbox. The value of **CUSTOM_LABEL** is changed from 10000 to 0.

## Relationship Attribute

Custom relationship. The value of **CUSTOM_LABEL** is changed from 10000 to 0.

Domestic partner. The value of **RELATION_DOMESTIC_PARTENER** is changed from 10 to 4.

Cooperative partner. The value of **RELATION_PARTNER** is changed from 4 to 10.

## SIP Address Attribute

Custom Session Initiation Protocol (SIP) address. The value of **CUSTOM_LABEL** is changed from 10000 to 0.
