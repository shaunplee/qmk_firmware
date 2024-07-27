// Copyright 2022 Michael McCoyd (@mmccoyd)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// Some boards have issues detecting handedness using the vbus voltage,
// such as Elite-C v3, but not v3.1 on, and apparently some ProMicro boards.
// For those boards, use usb detection instead.
// #define SPLIT_USB_DETECT

#define TAPPING_TERM 200
#define DEBOUNCE 40
#define EE_HANDS
#define SPLIT_USB_DETECT
#define SPLIT_USB_TIMEOUT 2000
#define SPLIT_USB_TIMEOUT_POLL 25
#define SPLIT_WATCHDOG_ENABLE
#define SPLIT_WATCHDOG_TIMEOUT 3000
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define CAPS_WORD_INVERT_ON_SHIFT
