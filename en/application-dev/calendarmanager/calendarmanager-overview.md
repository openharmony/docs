# Introduction to Calendar Kit

## Key Concepts

Calendar: a tool used to record dates, holidays, and important events.

## Introduction

Calendar Kit provides calendar and event management capabilities, including capabilities to obtain and create calendar events. A **CalendarManager** object is used to manage **Calendar** objects. A **Calendar** object contains the account information (**CalendarAccount**) and configuration information (**CalendarConfig**). Calendars and events are in the one-to-many relationship. That is, a calendar can have multiple events, but an event belongs to only one calendar.

## Working Principles

Calendar Kit provides a set of APIs for obtaining calendar accounts and writing calendar events to the obtained accounts. If an event has a reminder time set, the system sends a reminder to the user when the set time arrives.

## Constraints

- Calendar Kit requires manual authorization from the user for the permissions to read and write calendar events.

- Calendar Kit is only available in the stage model.
