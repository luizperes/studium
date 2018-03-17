#include <cstdio>
#include <studium/engine.hpp>

using namespace studium;
using namespace studium::render;
using namespace studium::entity;
using namespace studium::components;


class MyUpdater : public UpdateComponent
{
public:
    virtual void update(float dt) override
    {
        printf("Entered update\n");
        auto transform_ptr = parent.value().get_component<TransformComponent>();
        if(transform_ptr) {
            auto position = transform_ptr->get_position();
            position.x += 10.0f;
            transform_ptr->set_position(position);
            printf("Updated position\n");
            printf("New position: %s\n", glm::to_string(transform_ptr->get_position()).c_str());
        }

        printf("Exit update\n");
    }
};


int main(int argc, char** argv)
{
    printf("Running Studium version %s\n", engine::get_version_string());
    Renderer2D renderer;
    renderer.init();
    
    // Entity test
    auto entity = create_entity();
    {
        auto a_update = entity.add_component<MyUpdater>(new MyUpdater);
        auto a_render = entity.add_component<RenderComponent>(new RenderComponent);
        auto a_transf = entity.add_component<TransformComponent>(new TransformComponent);
        printf("Started\n");
        a_update->update(0.0f);
    }

    printf("Removing component\n");
    auto result = entity.remove_component<UpdateComponent>();
    printf("Component removed: %s\n", result ? "TRUE" : "FALSE");

    if(!entity.remove_component<UpdateComponent>())
        printf("Yeah, it was really removed\n");
    

    renderer.game_loop();
    renderer.unload();
    return 0;
}
