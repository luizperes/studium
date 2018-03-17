#include <studium/components.hpp>


glm::vec3
studium::components::TransformComponent::get_position() const
{
    return position;
}

glm::vec3
studium::components::TransformComponent::get_rotation() const
{
    return rotation;
}

glm::vec3
studium::components::TransformComponent::get_scale() const
{
    return scale;
}

glm::mat4
studium::components::TransformComponent::get_matrix()
{
    if(require_recalculation)
        this->model_mat_cache =
            translation_mat_cache *
            rotation_mat_cache *
            scale_mat_cache;
    return model_mat_cache;
}


void
studium::components::TransformComponent::set_position(glm::vec3 position)
{
    this->position = position;
    this->translation_mat_cache = glm::translate(glm::mat4(), position);
    require_recalculation = true;
}


void
studium::components::TransformComponent::set_rotation(glm::vec3 rotation)
{
    this->rotation = rotation;
    // TODO: REALLY set rotation
    require_recalculation = true;
}


void
studium::components::TransformComponent::set_scale(glm::vec3 scale)
{
    this->scale = scale;
    this->scale_mat_cache = glm::scale(glm::mat4(), scale);
    require_recalculation = true;
}
