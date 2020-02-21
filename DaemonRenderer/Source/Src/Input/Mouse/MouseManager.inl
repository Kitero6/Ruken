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

inline DAEvoid SubInputManager<EInputDevice::Mouse>::Update() noexcept
{
    for (auto const& action : m_actions)
    {
        auto it = m_events.find(action);

        if (it != m_events.end())
        {
            it->second.Invoke();
        }
    }

    m_actions.clear();
}

inline DAEvoid SubInputManager<EInputDevice::Mouse>::Reset() noexcept
{
    ClearQueue    ();
    ClearCallbacks();
}

inline DAEvoid SubInputManager<EInputDevice::Mouse>::Enqueue(Action<EInputDevice::Mouse>&& in_action)
{
    m_actions.emplace(std::forward<Action<EInputDevice::Mouse>>(in_action));
}

inline DAEvoid SubInputManager<EInputDevice::Mouse>::ClearQueue() noexcept
{
    m_actions.clear();
}

inline DAEvoid SubInputManager<EInputDevice::Mouse>::AddCallback(Action<EInputDevice::Mouse> const& in_action, Function const& in_callback)
{
    m_events[in_action] += in_callback;
}

inline DAEvoid SubInputManager<EInputDevice::Mouse>::RemoveCallback(Action<EInputDevice::Mouse> const& in_action, Function const& in_callback)
{
    (void)in_action;
    (void)in_callback;
}

inline DAEvoid SubInputManager<EInputDevice::Mouse>::ClearCallbacks() noexcept
{
    m_events.clear();
}