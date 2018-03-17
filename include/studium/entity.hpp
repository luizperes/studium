#pragma once

#include <studium/types.hpp>
#include <list>
#include <map>

namespace studium
{
    //! Wraps all functions and structures related to game object programming.
    namespace entity
    {
        class Entity;
        class Component;

        //! Represents a shared pointer to an entity's component.
        typedef Component* component_ptr;
        //! Represents a list of component shared pointers.
        typedef std::list<component_ptr>    component_lst;

        //! Yields a direct reference to the collection of entities,
        //  indexed by their GUID.
        std::map<u64, component_lst>& get_entity_collection();

        //! Creates a new entity for game usage.
        //  \return An instance of an Entity.
        //  \todo Make sure we use all pooled available entity slots
        //  before using a new GUID.
        Entity create_entity();

        /*!
         * \brief Yields an entity containing the desired GUID.
         * \param guid GUID for an existing entity.
         * \return A value that might be an Entity or not.
         */
        std::optional<Entity> entity_from(u64 guid);
        
        //! Represents a single entity with a permanent GUID.
        //  \note This class is final. Therefore, you cannot derive it.
        //  Due to obvious reasons, it is important to keep the OOP aspect
        //  of the entity system to a minimum.
        class Entity final
        {
        private:
            studium::u64 m_guid = 0;
            Entity() {}
        public:
            // Friend functions.
            friend Entity create_entity();
            friend std::optional<Entity> entity_from(u64);

            //! Yields the GUID for this entity.
            u64 get_guid() const;
           
            /*!
             * \brief Adds a component of any type to this entity's component
             * collection.
             *
             * \return A pointer to the newly-added component,
             * should it be needed.
             */
            template<typename T> T* add_component(T* component)
            {
                component->parent = *this;
                if(component) get_entity_collection()[this->m_guid].push_back(component);
                return component;
            }
            

            
            /*!
             * \brief Retrieves a component of the specified type for the current
             * entity.
             *
             * \return A const pointer to the desired component.
             * \warn DO NOT attempt to delete the component manually. Use the proper
             * function instead.
            */
            template<typename T> T* const get_component()
            {
                // Collect component list
                auto components = get_entity_collection().find(this->m_guid);
                if(components == get_entity_collection().end())
                    return {};

                // Collect component.
                // Cast every component to the desired type until we
                // find one that can actually be cast.
                for(auto component : components->second) {
                    T* downcast_ptr = dynamic_cast<T*>(component);
                    if(downcast_ptr)
                        return downcast_ptr;
                }
                
                // Couldn't find component
                return nullptr;
            }

            /*!
             * \brief Removes the component of the specified type for the current
             * entity.
             *
             * \return Whether the component existed for this entity, prior to its
             * removal.
             */
            template<typename T> bool remove_component()
            {
                // Collect component list
                auto components = get_entity_collection().find(this->m_guid);
                if(components == get_entity_collection().end())
                    return false;
                
                for(auto component : components->second) {
                    T* downcast_ptr = dynamic_cast<T*>(component);
                    if(downcast_ptr) {
                        components->second.remove(component);
                        delete component;
                        return true;
                    }
                }
                return false;
            }
        };

        
        //! Common interface for defining your own components.
        class Component
        {
            friend class Entity;
        protected:
            std::optional<Entity> parent = std::nullopt;
        public:
            virtual ~Component() {}
        };
    }
}
