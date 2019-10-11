#include <game-engine/graphics/scene.h>

Engine::Graphics::Scene::Scene()
: VAO(0),camera(DEFAULT_CAMERA),handler(nop_handler),update(nop_update)
{
	glGenVertexArrays(1, &VAO);
}

Engine::Graphics::Scene::Scene(Camera c)
: VAO(0),camera(c),handler(nop_handler),update(nop_update)
{
	glGenVertexArrays(1, &VAO);
}

Engine::Graphics::Scene::Scene(Camera c, std::function<void(IO::State const&, SDL_Event)> f)
: VAO(0),camera(c),handler(f),update(nop_update)
{
	glGenVertexArrays(1, &VAO);
}

Engine::Graphics::Scene::Scene(Camera c,
	std::function<void(IO::State const&, SDL_Event)> f,
	std::function<void(IO::State const&)> u)
: VAO(0),camera(c),handler(f),update(u)
{
	glGenVertexArrays(1, &VAO);
}

Engine::Graphics::Scene::~Scene()
{
	for(auto& buff : objects)
	{
		glDeleteBuffers(1, &buff.VBO);
		glDeleteBuffers(1, &buff.EBO);
	}

	glDeleteVertexArrays(1, &VAO);
}

void
Engine::Graphics::Scene::attach(Mesh o)
{
	MeshGL m;

	m.reset = o.reset;
	m.EBO_size = byte_length(o.EBO);

	glGenBuffers(1, &m.VBO);
	glGenBuffers(1, &m.EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, m.VBO);
	glBufferData(GL_ARRAY_BUFFER, byte_length(o.VBO), o.VBO.data(), GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,
		sizeof(Vertex), (GLvoid*)0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,
		sizeof(Vertex), (GLvoid*)offsetof(Vertex,normal));

	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE,
		sizeof(Vertex), (GLvoid*)offsetof(Vertex,color));

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m.EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, byte_length(o.EBO), o.EBO.data(), GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	objects.push_back(m);
}

void
Engine::Graphics::Scene::dettach(size_t i)
{
	glDeleteBuffers(1, &(objects[i].VBO));
	glDeleteBuffers(1, &(objects[i].EBO));
	objects.erase(objects.begin()+i);
}