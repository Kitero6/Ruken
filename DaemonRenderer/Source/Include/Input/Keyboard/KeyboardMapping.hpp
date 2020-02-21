/*
 *  MIT License
 *
 *  Copyright (c) 2019 Basile Combet, Philippe Yi
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NON INFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 */

#pragma once

#include <GLFW/glfw3.h>

#include "Containers/Pair.hpp"
#include "Containers/UnorderedMap.hpp"

#include "Input/Enums/Keyboard.hpp"

BEGIN_DAEMON_NAMESPACE

static UnorderedMap<DAEint32, EKey> KeyboardMapping =
{
    Pair<DAEint32, EKey>(GLFW_KEY_UNKNOWN,          EKey::Unknown),
    Pair<DAEint32, EKey>(GLFW_KEY_SPACE,            EKey::Space),
    Pair<DAEint32, EKey>(GLFW_KEY_APOSTROPHE,       EKey::Apostrophe),
    Pair<DAEint32, EKey>(GLFW_KEY_COMMA,            EKey::Comma),
    Pair<DAEint32, EKey>(GLFW_KEY_MINUS,            EKey::Minus),
    Pair<DAEint32, EKey>(GLFW_KEY_PERIOD,           EKey::Period),
    Pair<DAEint32, EKey>(GLFW_KEY_SLASH,            EKey::Slash),
    Pair<DAEint32, EKey>(GLFW_KEY_0,                EKey::Num0),
    Pair<DAEint32, EKey>(GLFW_KEY_1,                EKey::Num1),
    Pair<DAEint32, EKey>(GLFW_KEY_2,                EKey::Num2),
    Pair<DAEint32, EKey>(GLFW_KEY_3,                EKey::Num3),
    Pair<DAEint32, EKey>(GLFW_KEY_4,                EKey::Num4),
    Pair<DAEint32, EKey>(GLFW_KEY_5,                EKey::Num5),
    Pair<DAEint32, EKey>(GLFW_KEY_6,                EKey::Num6),
    Pair<DAEint32, EKey>(GLFW_KEY_7,                EKey::Num7),
    Pair<DAEint32, EKey>(GLFW_KEY_8,                EKey::Num8),
    Pair<DAEint32, EKey>(GLFW_KEY_9,                EKey::Num9),
    Pair<DAEint32, EKey>(GLFW_KEY_SEMICOLON,        EKey::Semicolon),
    Pair<DAEint32, EKey>(GLFW_KEY_EQUAL,            EKey::Equal),
    Pair<DAEint32, EKey>(GLFW_KEY_A,                EKey::A),
    Pair<DAEint32, EKey>(GLFW_KEY_B,                EKey::B),
    Pair<DAEint32, EKey>(GLFW_KEY_C,                EKey::C),
    Pair<DAEint32, EKey>(GLFW_KEY_D,                EKey::D),
    Pair<DAEint32, EKey>(GLFW_KEY_E,                EKey::E),
    Pair<DAEint32, EKey>(GLFW_KEY_F,                EKey::F),
    Pair<DAEint32, EKey>(GLFW_KEY_G,                EKey::G),
    Pair<DAEint32, EKey>(GLFW_KEY_H,                EKey::H),
    Pair<DAEint32, EKey>(GLFW_KEY_I,                EKey::I),
    Pair<DAEint32, EKey>(GLFW_KEY_J,                EKey::J),
    Pair<DAEint32, EKey>(GLFW_KEY_K,                EKey::K),
    Pair<DAEint32, EKey>(GLFW_KEY_L,                EKey::L),
    Pair<DAEint32, EKey>(GLFW_KEY_M,                EKey::M),
    Pair<DAEint32, EKey>(GLFW_KEY_N,                EKey::N),
    Pair<DAEint32, EKey>(GLFW_KEY_O,                EKey::A),
    Pair<DAEint32, EKey>(GLFW_KEY_P,                EKey::P),
    Pair<DAEint32, EKey>(GLFW_KEY_Q,                EKey::Q),
    Pair<DAEint32, EKey>(GLFW_KEY_R,                EKey::R),
    Pair<DAEint32, EKey>(GLFW_KEY_S,                EKey::S),
    Pair<DAEint32, EKey>(GLFW_KEY_T,                EKey::T),
    Pair<DAEint32, EKey>(GLFW_KEY_U,                EKey::U),
    Pair<DAEint32, EKey>(GLFW_KEY_V,                EKey::V),
    Pair<DAEint32, EKey>(GLFW_KEY_W,                EKey::W),
    Pair<DAEint32, EKey>(GLFW_KEY_X,                EKey::X),
    Pair<DAEint32, EKey>(GLFW_KEY_Y,                EKey::Y),
    Pair<DAEint32, EKey>(GLFW_KEY_Z,                EKey::Z),
    Pair<DAEint32, EKey>(GLFW_KEY_LEFT_BRACKET,     EKey::LeftBracket),
    Pair<DAEint32, EKey>(GLFW_KEY_BACKSLASH,        EKey::Backslash),
    Pair<DAEint32, EKey>(GLFW_KEY_RIGHT_BRACKET,    EKey::RightBracket),
    Pair<DAEint32, EKey>(GLFW_KEY_GRAVE_ACCENT,     EKey::GraveAccent),
    Pair<DAEint32, EKey>(GLFW_KEY_WORLD_1,          EKey::World1),
    Pair<DAEint32, EKey>(GLFW_KEY_WORLD_2,          EKey::World2),
    Pair<DAEint32, EKey>(GLFW_KEY_ESCAPE,           EKey::Escape),
    Pair<DAEint32, EKey>(GLFW_KEY_ENTER,            EKey::Enter),
    Pair<DAEint32, EKey>(GLFW_KEY_TAB,              EKey::Tab),
    Pair<DAEint32, EKey>(GLFW_KEY_BACKSPACE,        EKey::Backspace),
    Pair<DAEint32, EKey>(GLFW_KEY_INSERT,           EKey::Insert),
    Pair<DAEint32, EKey>(GLFW_KEY_DELETE,           EKey::Delete),
    Pair<DAEint32, EKey>(GLFW_KEY_RIGHT,            EKey::Right),
    Pair<DAEint32, EKey>(GLFW_KEY_LEFT,             EKey::Left),
    Pair<DAEint32, EKey>(GLFW_KEY_DOWN,             EKey::Down),
    Pair<DAEint32, EKey>(GLFW_KEY_UP,               EKey::Up),
    Pair<DAEint32, EKey>(GLFW_KEY_PAGE_UP,          EKey::PageUp),
    Pair<DAEint32, EKey>(GLFW_KEY_PAGE_DOWN,        EKey::PageDown),
    Pair<DAEint32, EKey>(GLFW_KEY_HOME,             EKey::Home),
    Pair<DAEint32, EKey>(GLFW_KEY_END,              EKey::End),
    Pair<DAEint32, EKey>(GLFW_KEY_CAPS_LOCK,        EKey::CapsLock),
    Pair<DAEint32, EKey>(GLFW_KEY_SCROLL_LOCK,      EKey::ScrollLock),
    Pair<DAEint32, EKey>(GLFW_KEY_NUM_LOCK,         EKey::NumLock),
    Pair<DAEint32, EKey>(GLFW_KEY_PRINT_SCREEN,     EKey::PrintScreen),
    Pair<DAEint32, EKey>(GLFW_KEY_PAUSE,            EKey::Pause),
    Pair<DAEint32, EKey>(GLFW_KEY_F1,               EKey::F1),
    Pair<DAEint32, EKey>(GLFW_KEY_F2,               EKey::F2),
    Pair<DAEint32, EKey>(GLFW_KEY_F3,               EKey::F3),
    Pair<DAEint32, EKey>(GLFW_KEY_F4,               EKey::F4),
    Pair<DAEint32, EKey>(GLFW_KEY_F5,               EKey::F5),
    Pair<DAEint32, EKey>(GLFW_KEY_F6,               EKey::F6),
    Pair<DAEint32, EKey>(GLFW_KEY_F7,               EKey::F7),
    Pair<DAEint32, EKey>(GLFW_KEY_F8,               EKey::F8),
    Pair<DAEint32, EKey>(GLFW_KEY_F9,               EKey::F9),
    Pair<DAEint32, EKey>(GLFW_KEY_F10,              EKey::F10),
    Pair<DAEint32, EKey>(GLFW_KEY_F11,              EKey::F11),
    Pair<DAEint32, EKey>(GLFW_KEY_F12,              EKey::F12),
    Pair<DAEint32, EKey>(GLFW_KEY_F13,              EKey::F13),
    Pair<DAEint32, EKey>(GLFW_KEY_F14,              EKey::F14),
    Pair<DAEint32, EKey>(GLFW_KEY_F15,              EKey::F15),
    Pair<DAEint32, EKey>(GLFW_KEY_F16,              EKey::F16),
    Pair<DAEint32, EKey>(GLFW_KEY_F17,              EKey::F17),
    Pair<DAEint32, EKey>(GLFW_KEY_F18,              EKey::F18),
    Pair<DAEint32, EKey>(GLFW_KEY_F19,              EKey::F19),
    Pair<DAEint32, EKey>(GLFW_KEY_F20,              EKey::F20),
    Pair<DAEint32, EKey>(GLFW_KEY_F21,              EKey::F21),
    Pair<DAEint32, EKey>(GLFW_KEY_F22,              EKey::F22),
    Pair<DAEint32, EKey>(GLFW_KEY_F23,              EKey::F23),
    Pair<DAEint32, EKey>(GLFW_KEY_F24,              EKey::F24),
    Pair<DAEint32, EKey>(GLFW_KEY_F25,              EKey::F25),
    Pair<DAEint32, EKey>(GLFW_KEY_KP_0,             EKey::NumPad0),
    Pair<DAEint32, EKey>(GLFW_KEY_KP_1,             EKey::NumPad1),
    Pair<DAEint32, EKey>(GLFW_KEY_KP_2,             EKey::NumPad2),
    Pair<DAEint32, EKey>(GLFW_KEY_KP_3,             EKey::NumPad3),
    Pair<DAEint32, EKey>(GLFW_KEY_KP_4,             EKey::NumPad4),
    Pair<DAEint32, EKey>(GLFW_KEY_KP_5,             EKey::NumPad5),
    Pair<DAEint32, EKey>(GLFW_KEY_KP_6,             EKey::NumPad6),
    Pair<DAEint32, EKey>(GLFW_KEY_KP_7,             EKey::NumPad7),
    Pair<DAEint32, EKey>(GLFW_KEY_KP_8,             EKey::NumPad8),
    Pair<DAEint32, EKey>(GLFW_KEY_KP_9,             EKey::NumPad9),
    Pair<DAEint32, EKey>(GLFW_KEY_KP_DECIMAL,       EKey::NumPadDecimal),
    Pair<DAEint32, EKey>(GLFW_KEY_KP_DIVIDE,        EKey::NumPadDivide),
    Pair<DAEint32, EKey>(GLFW_KEY_KP_MULTIPLY,      EKey::NumPadMultiply),
    Pair<DAEint32, EKey>(GLFW_KEY_KP_SUBTRACT,      EKey::NumPadSubtract),
    Pair<DAEint32, EKey>(GLFW_KEY_KP_ADD,           EKey::NumPadAdd),
    Pair<DAEint32, EKey>(GLFW_KEY_KP_ENTER,         EKey::NumPadEnter),
    Pair<DAEint32, EKey>(GLFW_KEY_KP_EQUAL,         EKey::NumPadEqual),
    Pair<DAEint32, EKey>(GLFW_KEY_LEFT_SHIFT,       EKey::LeftShift),
    Pair<DAEint32, EKey>(GLFW_KEY_LEFT_CONTROL,     EKey::LeftControl),
    Pair<DAEint32, EKey>(GLFW_KEY_LEFT_ALT,         EKey::LeftAlt),
    Pair<DAEint32, EKey>(GLFW_KEY_LEFT_SUPER,       EKey::LeftSuper),
    Pair<DAEint32, EKey>(GLFW_KEY_RIGHT_SHIFT,      EKey::RightShift),
    Pair<DAEint32, EKey>(GLFW_KEY_RIGHT_CONTROL,    EKey::RightControl),
    Pair<DAEint32, EKey>(GLFW_KEY_RIGHT_ALT,        EKey::RightAlt),
    Pair<DAEint32, EKey>(GLFW_KEY_RIGHT_SUPER,      EKey::RightSuper),
    Pair<DAEint32, EKey>(GLFW_KEY_MENU,             EKey::Menu)
};

END_DAEMON_NAMESPACE