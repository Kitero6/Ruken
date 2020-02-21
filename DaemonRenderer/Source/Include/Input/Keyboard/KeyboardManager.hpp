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

#include "Input/SubInputManager.hpp"

#include "KeyboardAction.hpp"
#include "KeyboardMapping.hpp"

#include "Functional/Event.hpp"

BEGIN_DAEMON_NAMESPACE

template<> class SubInputManager<EInputDevice::Keyboard>
{
    using Function = std::function<DAEvoid()>;

    private:

        #pragma region Members

        UnorderedSet<Action<EInputDevice::Keyboard>> m_actions;

        UnorderedMap<Action<EInputDevice::Keyboard>, Event<>> m_events;

        #pragma endregion

        #pragma region Methods



        #pragma endregion

    public:

        #pragma region Constructors and Destructor

        SubInputManager() noexcept = default;

        SubInputManager(SubInputManager const& in_copy) = delete;
        SubInputManager(SubInputManager&&      in_move) = delete;

        ~SubInputManager() noexcept = default;

        #pragma endregion

        #pragma region Operators

        SubInputManager& operator=(SubInputManager const& in_copy) = delete;
        SubInputManager& operator=(SubInputManager&&      in_move) = delete;

        #pragma endregion

        #pragma region Methods

        /**
         * \brief 
         */
        inline DAEvoid Update() noexcept;

        /**
         * \brief 
         */
        inline DAEvoid Reset() noexcept;

        /**
         * \brief
         *
         * \param in_action 
         */
        inline DAEvoid Enqueue(Action<EInputDevice::Keyboard>&& in_action);

        /**
         * \brief
         */
        inline DAEvoid ClearQueue() noexcept;

        /**
         * \brief
         *
         * \param in_action 
         * \param in_callback 
         */
        inline DAEvoid AddCallback(Action<EInputDevice::Keyboard> const& in_action, Function const& in_callback);

        /**
         * \brief
         *
         * \param in_action 
         * \param in_callback 
         */
        inline DAEvoid RemoveCallback(Action<EInputDevice::Keyboard> const& in_action, Function const& in_callback);

        /**
         * \brief
         */
        inline DAEvoid ClearCallbacks() noexcept;

        #pragma endregion
};

#include "Input/Keyboard/KeyboardManager.inl"

END_DAEMON_NAMESPACE