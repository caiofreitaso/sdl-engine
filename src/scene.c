#include "../include/scene/scene.h"

void scene_init(scene_t* s)
{
	glGenVertexArrays(1, &(s->VAO));
	array_init(&s->meshes, sizeof(mesh_t));
}

void scene_destroy(scene_t* s)
{
	FOR_EACH(mesh_t, m, s->meshes)
		glDeleteBuffers(1, &(m->VBO));
		glDeleteBuffers(1, &(m->EBO));
	END_FOR
	
	glDeleteVertexArrays(1, &(s->VAO));
	
	array_free(&(s->meshes));
}

void scene_attach(scene_t* s, array_t VBO, array_t EBO, GLuint idx)
{
	mesh_t mesh;
	mesh.reset = idx;
	mesh.EBO_size = EBO.size;

	glGenBuffers(1, &(mesh.VBO));
	glGenBuffers(1, &(mesh.EBO));

	glBindVertexArray(s->VAO);
	
	glBindBuffer(GL_ARRAY_BUFFER, mesh.VBO);
	glBufferData(GL_ARRAY_BUFFER,
		VBO.size * sizeof(vertex_t),
		VBO.array, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,
		sizeof(vertex_t), (GLvoid*)0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,
		sizeof(vertex_t), (GLvoid*)offsetof(vertex_t,normal));

	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE,
		sizeof(vertex_t), (GLvoid*)offsetof(vertex_t,color));

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh.EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,
		EBO.size * sizeof(unsigned),
		EBO.array, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	array_add(&(s->meshes), &mesh);
}

void scene_render(scene_t s)
{
	glBindVertexArray(s.VAO);
	
	FOR_EACH(mesh_t, m, s.meshes)
		glBindBuffer(GL_ARRAY_BUFFER, m->VBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m->EBO);
		glEnable(GL_PRIMITIVE_RESTART);
		glPrimitiveRestartIndex(m->reset);
		glDrawElements(GL_LINE_STRIP, m->EBO_size, GL_UNSIGNED_INT, 0);
	END_FOR

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	//glDisableClientState(GL_VERTEX_ARRAY);
}