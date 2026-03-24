# QMK Corne Keyboard Firmware

Custom [QMK](https://qmk.fm/) firmware for the [Corne (crkbd)](https://github.com/foostan/crkbd) split ergonomic mechanical keyboard, featuring Vial support, dual OLED displays with animations, and full RGB matrix lighting.

---

## Hardware

| Component | Details |
|-----------|---------|
| **Keyboard** | Corne (crkbd) — split 3×6+3 layout |
| **Microcontroller** | RP2040 (Raspberry Pi–based) |
| **Keys** | 42 total (21 per half) |
| **Displays** | Dual 128×32 OLED (I²C, SDA=GP2 / SCL=GP3) |
| **RGB LEDs** | 54 × WS2812 addressable LEDs (27 per half, data pin GP0) |
| **Split communication** | Serial via GP1 |
| **Handedness** | Left detected via GP21 (low = left) |
| **USB VBUS detection** | GP19 |
| **Bootloader** | RP2040 (double-tap reset to enter flash mode) |

---

## Features

- **Vial** real-time keymap editing via the [Vial GUI](https://vial.rocks/)
- **4 keymap layers** (base QWERTY + numbers/symbols + navigation/numpad + RGB/system)
- **8 dynamic layers** configurable in Vial
- **Mod-Tap (MT)** and **Layer-Tap (LT)** keys for compact ergonomic layout
- **Auto Shift** — hold any key slightly longer to get its shifted character
- **Combos**, **Key Overrides**, **Tap Dance**, and **Macros** (all Vial-editable)
- **WPM tracking** synced across both halves
- **NKRO** (N-Key Rollover)
- **Mousekey** support
- **30+ RGB matrix effects** (default: cycle left-right)
- **Luna cat OLED animation** — reacts to your typing speed
- **Audi four-ring logo** on the right OLED

---

## Keymap Layers

### Layer 0 — Base (QWERTY)

```
┌─────────┬───┬───┬───┬───┬───┐   ┌───┬───┬───┬───┬───┬──────────┐
│ ESC/GUI │ Q │ W │ E │ R │ T │   │ Y │ U │ I │ O │ P │  [{/GUI  │
├─────────┼───┼───┼───┼───┼───┤   ├───┼───┼───┼───┼───┼──────────┤
│ TAB/CTL │ A │ S │ D │ F │ G │   │ H │ J │ K │ L │ ; │  '"/CTL  │
├─────────┼───┼───┼───┼───┼───┤   ├───┼───┼───┼───┼───┼──────────┤
│   ALT   │ Z │ X │ C │ V │ B │   │ N │ M │ , │ . │ / │   ]}     │
└─────────┴───┴───┴───┴───┴───┘   └───┴───┴───┴───┴───┴──────────┘
                ┌──────────┬───────────────┬───────┐
                │BSPC/Lyr1 │ SPACE/Shift   │ENT/L2 │
                └──────────┴───────────────┴───────┘
                ┌───────┬───────────────┬──────────┐
                │ENT/L2 │ SPACE/Shift   │DEL/Lyr1  │
                └───────┴───────────────┴──────────┘
```

> Keys marked `/GUI`, `/CTL`, `/Shift`, `/LyrN` use **Mod-Tap** or **Layer-Tap** — tap for the primary character, hold for the modifier or layer.

---

### Layer 1 — Numbers & Symbols

Hold `BSPC` (left thumb) or `DEL` (right thumb) to activate.

```
┌────┬────┬────┬────┬────┬────┐   ┌────┬────┬────┬────┬────┬────┐
│ F1 │ F2 │ F3 │ F4 │ F5 │ F6 │   │ F7 │ F8 │ F9 │F10 │F11 │F12 │
├────┼────┼────┼────┼────┼────┤   ├────┼────┼────┼────┼────┼────┤
│    │ !  │ @  │ #  │ $  │ %  │   │ ^  │ &  │ *  │ (  │ )  │ _  │
├────┼────┼────┼────┼────┼────┤   ├────┼────┼────┼────┼────┼────┤
│ALT │ 1  │ 2  │ 3  │ 4  │ 5  │   │ 6  │ 7  │ 8  │ 9  │ 0  │INS │
└────┴────┴────┴────┴────┴────┘   └────┴────┴────┴────┴────┴────┘
              ┌──────┬──────┬──────┐   ┌──────┬──────┬──────┐
              │      │      │ L3   │   │  L3  │      │      │
              └──────┴──────┴──────┘   └──────┴──────┴──────┘
```

---

### Layer 2 — Navigation & Numpad

Hold `ENT` (left or right thumb) to activate.

```
┌─────┬───┬───┬───┬───┬───┐   ┌─────┬──────┬──────┬──────┬──────┬─────┐
│  `  │ / │ 7 │ 8 │ 9 │ - │   │  =  │ HOME │  UP  │ PGUP │ PREV │ WIN │
├─────┼───┼───┼───┼───┼───┤   ├─────┼──────┼──────┼──────┼──────┼─────┤
│     │ * │ 4 │ 5 │ 6 │ + │   │VOL+ │ LEFT │ DOWN │RIGHT │ PLAY │  \  │
├─────┼───┼───┼───┼───┼───┤   ├─────┼──────┼──────┼──────┼──────┼─────┤
│ NUM │ 0 │ 1 │ 2 │ 3 │ . │   │VOL- │ END  │ PSCR │ PGDN │ NEXT │ CTL │
└─────┴───┴───┴───┴───┴───┘   └─────┴──────┴──────┴──────┴──────┴─────┘
          ┌──────┬──────┬──────┐   ┌──────┬──────┬──────┐
          │  L3  │      │      │   │      │      │  L3  │
          └──────┴──────┴──────┘   └──────┴──────┴──────┘
```

---

### Layer 3 — RGB & System

Activated by reaching Layer 3 via the thumb keys while on Layer 1 or 2.

```
Left half                              Right half
┌───────────┬────────┬────────┬────────┬─────────┬──────────┐   ┌──────────┬─────────┬────────┬────────┬────────┬───────────┐
│ RGB_PLAIN │ AS_DOWN│ AS_TOGG│  AS_UP │  BOOT   │          │   │          │  BOOT   │ AS_DOWN│ AS_TOGG│  AS_UP │ RGB_PLAIN │
├───────────┼────────┼────────┼────────┼─────────┼──────────┤   ├──────────┼─────────┼────────┼────────┼────────┼───────────┤
│  RGB_TOG  │ RGB_HUI│ RGB_SAI│ RGB_VAI│ RGB_SPI │  RGB_MOD │   │  RGB_MOD │ RGB_SPI │ RGB_VAI│ RGB_SAI│ RGB_HUI│  RGB_TOG  │
├───────────┼────────┼────────┼────────┼─────────┼──────────┤   ├──────────┼─────────┼────────┼────────┼────────┼───────────┤
│           │ RGB_HUD│ RGB_SAD│ RGB_VAD│ RGB_SPD │ RGB_RMOD │   │ RGB_RMOD │ RGB_SPD │ RGB_VAD│ RGB_SAD│ RGB_HUD│           │
└───────────┴────────┴────────┴────────┴─────────┴──────────┘   └──────────┴─────────┴────────┴────────┴────────┴───────────┘
```

| Key | Action |
|-----|--------|
| `RGB_TOG` | Toggle RGB on/off |
| `RGB_MOD` / `RGB_RMOD` | Cycle through effects forward/backward |
| `RGB_HUI/D` | Increase/decrease hue |
| `RGB_SAI/D` | Increase/decrease saturation |
| `RGB_VAI/D` | Increase/decrease brightness |
| `RGB_SPI/D` | Increase/decrease animation speed |
| `RGB_PLAIN` | Set solid color mode |
| `AS_TOGG` | Toggle Auto Shift |
| `AS_UP/DOWN` | Increase/decrease Auto Shift timeout |
| `BOOT` | Enter bootloader (for flashing) |

---

## OLED Displays

### Left Display
- **Luna the cat** — an animated pixel-art cat whose behavior changes with your typing speed:
  - **Sitting** (0–10 WPM)
  - **Walking** (10–40 WPM)
  - **Running** (40+ WPM)
- **Active layer** indicator
- **Modifier key** status (GUI, ALT, CTRL, SHIFT)

### Right Display
- **Audi four-ring logo** (static bitmap)

---

## Building & Flashing

### Prerequisites

1. Set up the [QMK environment](https://docs.qmk.fm/newbs_getting_started)
2. Clone the QMK firmware repository
3. Copy or symlink this repository's `keyboards/crkbd` folder into your QMK `keyboards/` directory

### Build

```bash
qmk compile -kb crkbd -km vial
```

### Flash

Put the keyboard into bootloader mode by **double-tapping the reset button** (or pressing `BOOT` on Layer 3), then:

```bash
qmk flash -kb crkbd -km vial
```

Flash each half separately while connected via USB.

### Vial (live keymap editing)

Download the [Vial app](https://get.vial.today/) and connect your keyboard. Changes take effect immediately without reflashing.

---

## Configuration Highlights

| Setting | Value |
|---------|-------|
| OLED timeout | 60 seconds |
| OLED brightness | 180 / 255 |
| RGB max brightness | 128 / 255 |
| Default RGB effect | Cycle left-right |
| Debounce | 5 ms |
| Dynamic layers | 8 |
| Combo entries | 64 |
| Macro slots | 32 |

---

## Repository Structure

```
keyboards/
└── crkbd/
    ├── config.h          # Hardware configuration (pins, OLED, RGB)
    ├── crkbd.c           # Keyboard implementation
    ├── crkbd.h           # Header definitions
    ├── keyboard.json     # QMK keyboard metadata & LED positions
    ├── rules.mk          # Build rules
    ├── lib/
    │   └── glcdfont.c    # Custom OLED font
    └── keymaps/
        └── vial/
            ├── keymap.c  # Layer definitions
            ├── config.h  # Vial & dynamic keymap settings
            ├── rules.mk  # Vial build flags
            ├── oled.c    # OLED display logic & Luna animation
            └── vial.json # Vial GUI layout definition
```

---

## References

- [QMK Firmware](https://docs.qmk.fm/)
- [Corne keyboard (foostan)](https://github.com/foostan/crkbd)
- [Vial configurator](https://vial.rocks/)
- [RP2040 QMK support](https://docs.qmk.fm/platformdev_rp2040)
