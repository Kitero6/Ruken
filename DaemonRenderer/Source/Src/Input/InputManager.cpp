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

#include "Input/Input.hpp"
#include "Input/InputHandler.hpp"
#include "Input/InputManager.hpp"

/* TODO Needs to be removed when Kernel is done TODO */

DAEMON_NAMESPACE::InputManager* DAEMON_NAMESPACE::GInputManager = nullptr;

/* TODO Needs to be removed when Kernel is done TODO */

USING_DAEMON_NAMESPACE

DAEvoid InputManager::Enqueue(Action<EInputDevice::Mouse>&& in_action)
{
    m_mouse_manager.Enqueue(std::forward<Action<EInputDevice::Mouse>>(in_action));
}

DAEvoid InputManager::Enqueue(Action<EInputDevice::Keyboard>&& in_action)
{
    m_keyboard_manager.Enqueue(std::forward<Action<EInputDevice::Keyboard>>(in_action));
}

DAEvoid InputManager::EnqueueMousePosition(Vector2<DAEdouble>&& in_position)
{
    (void)in_position;
}

DAEvoid InputManager::EnqueueMouseScroll(Vector2<DAEdouble>&& in_value)
{
    (void)in_value;
}

DAEbool InputManager::Initialize() noexcept
{
    Input       ::m_input_manager = this;
    InputHandler::m_input_manager = this;

    /* TODO Needs to be removed when Kernel is done TODO */
    
    GInputManager = this;

    /* TODO Needs to be removed when Kernel is done TODO */

    return true;
}

DAEvoid InputManager::Update() noexcept
{
    m_mouse_manager   .Update();
    m_keyboard_manager.Update();
}

DAEvoid InputManager::Shutdown() noexcept
{

}