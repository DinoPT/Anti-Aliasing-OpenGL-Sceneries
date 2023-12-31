#ifndef TEXTURED_QUAD_H
#define TEXTURED_QUAD_H

#include <string>
#include <vector>
#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>

struct TextureGenProperties;

// Model a simple textured quad oriented to face along the +z axis (so the textured quad faces the viewer in (right-handed) eye coordinate space.  The quad is modelled using VBOs and VAOs and rendered using the basic texture shader in Resources\Shaders\basic_texture.vert and Resources\Shaders\basic_texture.frag

class TexturedQuad{

private:

	GLuint					quadVertexArrayObj;

	GLuint					quadVertexBuffer;
	GLuint					quadTextureCoordBuffer;

	GLuint					quadShader;

	GLuint					texture;

	//
	// Private API
	//

	void loadShader();
	void setupVAO(bool invertV);


	//
	// Public API
	//

public:

	TexturedQuad(const std::string& texturePath, bool invertV = false);
	TexturedQuad(GLuint initTexture, bool invertV = false);
	TexturedQuad(const std::string& texturePath, const TextureGenProperties& textureProperties, bool invertV = false);

	~TexturedQuad();

	void render(const glm::mat4& T);
};

#endif