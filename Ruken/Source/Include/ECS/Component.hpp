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

#include "Meta/Meta.hpp"
#include "Meta/Assert.hpp"

#include "ECS/ComponentBase.hpp"
#include "ECS/ComponentItem.hpp"

BEGIN_DAEMON_NAMESPACE

/**
 * \brief A component is a simple data container which contains no behavior, no code logic to transform its data.
 * \tparam TFields Fields of the component
 * \tparam TUniqueId Unique ID of the component.
 *                   Ideally this would be generated automatically at compile time but doing so in c++ is
 *                   really hard and not 100% reliable. Since this ID must be unique for each component, the best way to maintain it
 *                   is using an enum enumerating every component of the game. This way if a component is deleted, the ids of every other
 *                   component will be maintained automatically. This enum must use the default values in order to work. See examples for more info.
 */
template <DAEsize TUniqueId, typename... TFields>
class Component final : public ComponentBase
{
    DAEMON_STATIC_ASSERT(sizeof...(TFields) > 0               , "A component must have at least one field, use a TagComponent instead."    );
    DAEMON_STATIC_ASSERT(TUniqueId < DAEMON_MAX_ECS_COMPONENTS, "Please increate the maximum amount of ECS components to run this program.");

    public:

        using Item   = ComponentItem<TFields...>;
        using Layout = typename Item::Layout;

    private:

        #pragma region Members

        // Storage of the component
        typename Layout::ContainerType m_storage {};

        #pragma endregion 

    public:

        static constexpr DAEsize id = TUniqueId;

        #pragma region Constructors

        Component()                         = default;
        Component(Component const& in_copy) = default;
        Component(Component&&      in_move) = default;
        virtual ~Component() override       = default;

        #pragma endregion

        #pragma region Methods

        /**
         * \brief Creates an item into the component
         * \param in_item item to push back
         * \return Created item id
         */
        EntityID CreateItem(Item&& in_item) noexcept;
        EntityID CreateItem()               noexcept override;

        /**
         * \brief Returns the count of items in this component
         * \return Component item count
         */
        DAEsize GetItemCount() const noexcept override;

        /**
         * \brief Returns a view containing all the requested fields of a given entity
         * \tparam TView View type
         * \param in_entity Entity to fetch
         * \return View containing all the requested fields of the given entity
         */
        template <typename TView>
        auto GetItemView(EntityID in_entity) noexcept;

        #pragma endregion 

        #pragma region Operators

        Component& operator=(Component const& in_copy) = default;
        Component& operator=(Component&&      in_move) = default;

        #pragma endregion
};

/**
 * \brief Shorthand to declare a component named "<in_component_name>Component"
 * \param in_component_name Name of the component as defined in the component table
 * \param ... Fields of the component. Theses must inherit from the ComponentField class
 */
#define DAEMON_DEFINE_COMPONENT(in_component_name, ...)\
    using DAEMON_GLUE(in_component_name, Component) = Component<static_cast<::DAEMON_NAMESPACE::DAEsize>(EComponentTable::in_component_name), __VA_ARGS__>
    
/**
 * \brief Creates an enum called EComponentTable used to keep track of every available
 *        component in the ECS. It is also used to create and maintain every component ID.
 *        See the Component class for more info.
 */
#define DAEMON_DEFINE_COMPONENT_TABLE(...)\
    enum class EComponentTable { __VA_ARGS__ }

#include "ECS/Component.inl"

END_DAEMON_NAMESPACE