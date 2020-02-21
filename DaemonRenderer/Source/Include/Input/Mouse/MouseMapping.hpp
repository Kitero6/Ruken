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
#include "Containers/UnorderedSet.hpp"

#include "Input/Enums/Mouse.hpp"

BEGIN_DAEMON_NAMESPACE

static UnorderedMap<DAEint32, EMouseButton> MouseMapping =
{
    Pair<DAEint32, EMouseButton>(GLFW_MOUSE_BUTTON_1, EMouseButton::Left),
    Pair<DAEint32, EMouseButton>(GLFW_MOUSE_BUTTON_2, EMouseButton::Right),
    Pair<DAEint32, EMouseButton>(GLFW_MOUSE_BUTTON_3, EMouseButton::Middle),
    Pair<DAEint32, EMouseButton>(GLFW_MOUSE_BUTTON_4, EMouseButton::Button3),
    Pair<DAEint32, EMouseButton>(GLFW_MOUSE_BUTTON_5, EMouseButton::Button4),
    Pair<DAEint32, EMouseButton>(GLFW_MOUSE_BUTTON_6, EMouseButton::Button5),
    Pair<DAEint32, EMouseButton>(GLFW_MOUSE_BUTTON_7, EMouseButton::Button6),
    Pair<DAEint32, EMouseButton>(GLFW_MOUSE_BUTTON_8, EMouseButton::Button7),
};

END_DAEMON_NAMESPACE