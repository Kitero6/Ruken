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

#include "Vector/Vector.hpp"

#include "Mouse/MouseManager.hpp"

#include "Keyboard/KeyboardManager.hpp"

#include "Debug/Logging/Logger.hpp"

BEGIN_DAEMON_NAMESPACE

/**
 * \brief 
 */
class InputManager
{
    /**
     * \brief 
     */
    friend class Window;

    private:

        #pragma region Members

        Logger* m_logger = nullptr;

        SubInputManager<EInputDevice::Mouse>    m_mouse_manager;
        SubInputManager<EInputDevice::Keyboard> m_keyboard_manager;

        #pragma endregion

        #pragma region Methods

        DAEvoid Enqueue(Action<EInputDevice::Mouse>&& in_action);

        DAEvoid Enqueue(Action<EInputDevice::Keyboard>&& in_action);

        DAEvoid EnqueueMousePosition(Vector2<DAEdouble>&& in_position);

        DAEvoid EnqueueMouseScroll(Vector2<DAEdouble>&& in_value);

        #pragma endregion

    public:

        #pragma region Constructors and Destructor

        InputManager() noexcept = default;

        InputManager(InputManager const& in_copy) = delete;
        InputManager(InputManager&&      in_move) = delete;

        ~InputManager() noexcept = default;

        #pragma endregion

        #pragma region Operators

        InputManager& operator=(InputManager const& in_copy) = delete;
        InputManager& operator=(InputManager&&      in_move) = delete;

        #pragma endregion

        #pragma region Methods

        /**
         * \brief 
         *
         * \return 
         */
        DAEbool Initialize() noexcept;

        /**
         * \brief 
         */
        DAEvoid Update() noexcept;

        /**
         * \brief 
         */
        DAEvoid Shutdown() noexcept;



        #pragma endregion
};

/* TODO Needs to be removed when Kernel is done TODO */

extern InputManager* GInputManager;

/* TODO Needs to be removed when Kernel is done TODO */

END_DAEMON_NAMESPACE