#include <studium/entity.hpp>

// Global values with respect to component management
namespace studium
{
    namespace entity
    {
        // Global identifier for entities.
        static studium::u64 NEXT_GUID = 0;

        // Global storage for components of every entity.
        static std::map<u64, component_lst> COMPONENT_COLLECTION;
    }
}



std::map<studium::u64, studium::entity::component_lst>&
studium::entity::get_entity_collection()
{
    return COMPONENT_COLLECTION;
}



studium::entity::Entity
studium::entity::create_entity()
{
    Entity e;
    e.m_guid = NEXT_GUID;
    NEXT_GUID++;
    return e;
}


std::optional<studium::entity::Entity>
studium::entity::entity_from(u64 guid)
{
    // TODO: Once we enable entity pooling,
    // also check if not on pool
    if(guid >= NEXT_GUID)
        return std::nullopt;
    Entity e;
    e.m_guid = guid;
    return e;
}


// ======= Entity ======= //


studium::u64
studium::entity::Entity::get_guid() const
{
    return this->m_guid;
}


