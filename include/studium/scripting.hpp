#pragma once

#ifdef STUDIUM_SCRIPTING

#include <studium/entity.hpp>

namespace studium
{
    namespace components
    {
        /*!
         * \brief Generic component for a scripted entity.
         * \todo Still needs to be usable.
         */
        class ScriptingComponent : public studium::entity::Component
        {
        public:
            /*!
             * \brief Creates the scripting component.
             * \param path Path to the script file.
             */
            ScriptingComponent(const char* path);
        };
    }
}

#endif
