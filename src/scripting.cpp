#ifdef STUDIUM_SCRIPTING

#include <studium/scripting.hpp>
#include <chicken.h>
#include <cstring>

// Reference: http://wiki.call-cc.org/man/4/Embedding

namespace studium
{
    // This namespace is internal.
    namespace _scripting
    {
        bool CHICKEN_INITIALIZED = false;
        
        inline void initialize();
    }
}


inline void
studium::_scripting::initialize()
{
    if(!CHICKEN_INITIALIZED) {
        CHICKEN_run(CHICKEN_default_toplevel);
        CHICKEN_INITIALIZED = true;
    }
}



// ======== ScriptingComponent ======== //

studium::components::ScriptingComponent::ScriptingComponent(const char* path)
{
    studium::_scripting::initialize();

    char* filename = new char[strlen(path)];
    strcpy(filename, path);
    CHICKEN_load(filename); // TODO: check return
    delete [] filename;
}


#endif
