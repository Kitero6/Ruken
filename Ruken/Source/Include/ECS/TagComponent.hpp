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

#include "Config.hpp"

#include "Meta/Assert.hpp"
#include "ECS/ComponentBase.hpp"

BEGIN_DAEMON_NAMESPACE

/**
 * \brief A tag component does not hold any data, its only purpose is to differentiate 2 entities from each other by "tagging" it.
 * \tparam TUniqueId Unique ID of the component.
 *                   Ideally this would be generated automatically at compile time but doing so in c++ is
 *                   really hard and not 100% reliable. Since this ID must be unique for each component, the best way to maintain it
 *                   is using an enum enumerating every component of the game. This way if a component is deleted, the ids of every other
 *                   component will be maintained automatically. This enum must use the default values in order to work. See examples for more info.
 */
template <DAEsize TUniqueId>
class TagComponent final : public ComponentBase
{
    DAEMON_STATIC_ASSERT(TUniqueId < DAEMON_MAX_ECS_COMPONENTS, "Please increate the maximum amount of ECS components to run this program.");

    private:

        #pragma region Methods

        // The size of the component must still be tracked in case where the
        // archetype we are living in queries us to find its size.
        // TODO(Basile): That job could be handled by the Archetype instead
        DAEsize m_component_size {0};

        #pragma endregion 

    public:

        static constexpr DAEsize id = TUniqueId;

        #pragma region Constructors

        TagComponent()                            = default;
        TagComponent(TagComponent const& in_copy) = default;
        TagComponent(TagComponent&&      in_move) = default;
        virtual ~TagComponent()                   = default;

        #pragma endregion

        #pragma region Methods

        /**
         * \brief Creates an item into the component
         * \return Created item id
         */
        EntityID CreateItem() noexcept override;

        /**
         * \brief Returns the count of items in this component
         * \return Component item count
         */
        DAEsize GetItemCount() const noexcept override;

        #pragma endregion 

        #pragma region Operators

        TagComponent& operator=(TagComponent const& in_copy) = default;
        TagComponent& operator=(TagComponent&&      in_move) = default;

        #pragma endregion
};

#include "ECS/TagComponent.inl"

/**
 * \brief Shorthand to declare a tag component named "<in_component_name>Component"
 * \param in_component_name Name of the component as defined in the component table
 */
#define DAEMON_DEFINE_TAG_COMPONENT(in_component_name, ...)\
    using DAEMON_GLUE(in_component_name, Component) = TagComponent<static_cast<::DAEMON_NAMESPACE::DAEsize>(EComponentTable::in_component_name)>

END_DAEMON_NAMESPACE