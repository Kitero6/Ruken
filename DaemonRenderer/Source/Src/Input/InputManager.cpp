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

#include "Input/InputManager.hpp"

#include "Input/Input.hpp"
#include "Input/InputHandler.hpp"

/* TODO Needs to be removed when Kernel is done TODO */

DAEMON_NAMESPACE::InputManager* DAEMON_NAMESPACE::GInputManager = nullptr;

/* TODO Needs to be removed when Kernel is done TODO */

USING_DAEMON_NAMESPACE

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

}

DAEvoid InputManager::Shutdown() noexcept
{

}