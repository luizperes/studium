#pragma once
#include <studium/types.hpp>
#include <studium/render.hpp>
#include <studium/entity.hpp>
#include <studium/components.hpp>
#include <studium/scripting.hpp>

//! Global namespace for all Studium controls.
namespace studium
{
    //! Wraps controls which make easier to set up basic startup options.
    namespace engine
    {
        //! Yields a const pointer to the version string.
        const char* get_version_string();
    }
}

