#pragma once
#include <studium/types.hpp>
#include <studium/entity.hpp>
#include <studium/render.hpp>

namespace studium
{
    //! Wraps common components which you might want to use to build your entities.
    namespace components
    {
        //! Generic component for an object that performs logic update whenever it can.
        class UpdateComponent : public studium::entity::Component
        {
        public:
            virtual ~UpdateComponent() {}
            /*!
             * \brief Performs a logic update for the entity.
             * \param delta_time Time difference, in milliseconds,
             * from last to current frame.
             */
            virtual void update(float delta_time) {};
        };
            
        //! Generic component for an object that is drawn to the screen.
        class RenderComponent : public studium::entity::Component
        {
        public:
            virtual ~RenderComponent() {}
            /*!
             * \brief Performs on-screen drawing for the entity.
             * \param renderer Direct reference to the renderer.
             */
            virtual void draw(studium::render::Renderer2D& renderer) {};
        };
            
        /*!
         * \brief Generic component for an object that can be repositioned
         * on screen.
         */
        class TransformComponent : public studium::entity::Component
        {
        private:
            bool require_recalculation = false;
            glm::mat4 translation_mat_cache;
            glm::mat4 rotation_mat_cache;
            glm::mat4 scale_mat_cache;
            glm::mat4 model_mat_cache;
        protected:
            //! Absolute position for the transform.
            glm::vec3 position;
            //! Absolute rotation for the transform.
            glm::vec3 rotation;
            //! Absolute scale for the transform.
            glm::vec3 scale = glm::vec3(1.0f);
        public:
            virtual ~TransformComponent() {}

            //! Yields the position for the transform.
            glm::vec3 get_position() const;
            //! Yields the rotation for the transform.
            //  \todo This field might need a rework.
            glm::vec3 get_rotation() const;
            //! Yields the scale for the transform.
            glm::vec3 get_scale()    const;
            /*!
             * \brief Yields the Model matrix for the entity.
             * \note If any of the attributes on this transform
             * component has been changed, the cached matrix is
             * recalculated.
             */
            glm::mat4 get_matrix();

            /*!
             * \brief Sets the position to a new value.
             * \param position The new position to be set.
             */
            void set_position(glm::vec3 position);
            /*!
             * \brief Sets the rotation to a new value.
             * \param rotation The new rotation to be set.
             * \todo This function needs a way to really set the
             * rotation for a specific axis. Maybe use quaternions?
             */
            void set_rotation(glm::vec3 rotation);
            /*!
             * \brief Sets the scale to a new value.
             * \param scale The new scale to be set.
             */
            void set_scale(glm::vec3 scale);
        };
    }
}
