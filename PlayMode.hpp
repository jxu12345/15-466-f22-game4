#include "Mode.hpp"

#include "Scene.hpp"
#include "Sound.hpp"

#include <glm/glm.hpp>

#include <vector>
#include <deque>

#include "TextRendering.hpp"
#include "data_path.hpp"

struct PlayMode : Mode {
	PlayMode();
	virtual ~PlayMode();

	//functions called by main loop:
	virtual bool handle_event(SDL_Event const &, glm::uvec2 const &window_size) override;
	virtual void update(float elapsed) override;
	virtual void draw(glm::uvec2 const &drawable_size) override;

	//----- game state -----

	//input tracking:
	struct Button {
		uint8_t downs = 0;
		uint8_t pressed = 0;
	} left, right, down, up;

	//local copy of the game scene (so code can change it during gameplay):
	Scene scene;

	TextRenderer *text_renderer = new TextRenderer(data_path("Roboto-Medium.ttf"), 48);
	
	//camera:
	Scene::Camera *camera = nullptr;

	//user input:
	std::string user_input;

	// background color:
	glm::vec3 bg_color = glm::vec3(0.0f, 0.0f, 0.0f);

};
