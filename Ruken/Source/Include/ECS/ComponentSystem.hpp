/*
 *  MIT License
 *
 *  Copyright (c) 2019-2020 Basile Combet, Philippe Yi
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

#include "Build/Namespace.hpp"
#include "Types/FundamentalTypes.hpp"
#include "ECS/ComponentSystemBase.hpp"

BEGIN_RUKEN_NAMESPACE

template <typename... TComponents>
class ComponentSystem : public ComponentSystemBase
{
    public:

        #pragma region Constructors

        ComponentSystem() noexcept;
        ComponentSystem(ComponentSystem const& in_copy) = default;
        ComponentSystem(ComponentSystem&&      in_move) = default;
        virtual ~ComponentSystem()                      = default;

        #pragma endregion

        #pragma region Methods

        /*
        virtual RkVoid OnUpdate() const noexcept = 0;
        virtual RkVoid OnQuery () const noexcept = 0;
        */

        #pragma endregion

        #pragma region Operators

        ComponentSystem& operator=(ComponentSystem const& in_copy) = default;
        ComponentSystem& operator=(ComponentSystem&&      in_move) = default;

        #pragma endregion
};

#include "ECS/ComponentSystem.inl"

END_RUKEN_NAMESPACE