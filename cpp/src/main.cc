#include <sstream>

#include <game-engine/io/scene.h>
#include <game-engine/graphics/render.h>

using namespace GameEngine;

int
main(int argc, char **args) {
  auto &GAME_STATE = THE_GAME.state;

  if (!THE_GAME.init("Engine Test")) {
    IO::Scene s;
    s.end = false;
    s.event_handler = IO::EventHandlers::NOP;
    s.update = IO::UpdateHandlers::WASD;

    s.camera = Graphics::DEFAULT_CAMERA;
    s.camera.position = { 0, 0, 10 };

    float angleDown = 10;

    s.camera.target[0] = 0;
    s.camera.target[1] = sin(angleDown * Graphics::FOV_ANGLE_RATIO);
    s.camera.target[2] -= cos(angleDown * Graphics::FOV_ANGLE_RATIO);
    s.camera.v_fov = 20;

    
    {
      std::vector<Graphics::Vertex> vertices;
      std::vector<unsigned> face_indicies;

      for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11; j++) {
          vertices.push_back(Graphics::Vertex {
            .position = { i, j, (i+j) % 2 },
            .normal = { 1.0f, 0.0f, 0.0f },
            .color = { ((0.0f + i)/10), 0.0f, ((0.0f + j)/10) }
          });
        }
      }
      for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 11; j++) {
          face_indicies.push_back(i * 11 + j);
          face_indicies.push_back((i + 1) * 11 + j);
        }

        if (i < 9) {
          face_indicies.push_back(121);
        }
      }

      {
        std::vector<Point3f> normals;
        for (int i = 0; i < 227; i++) {
          if (face_indicies[i+2] == 121)
            i += 2;
          auto a = vertices[face_indicies[i]].position;
          auto b = vertices[face_indicies[i+1]].position;
          auto c = vertices[face_indicies[i+2]].position;
          auto normal = Point3f::normal(a, b, c);
          auto area = Point3f::area(a, b, c);
          if (normal[2] < 0.0f)
            normal *= -1.0f;
          normals.push_back(normal * area);
        }
  
        vertices[0].normal = normals[0].normalized();
        vertices[10].normal = (normals[19] + normals[18]).normalized();
        for (int i = 1; i < 10; i++) {
          vertices[i].normal = (normals[2*i] + normals[2*i-1] + normals[2*i-2])
            .normalized();
        }
        for (int i = 1; i < 10; i++) {
          vertices[i*10].normal = (normals[20*(i-1)] + normals[22*(i-1)] + normals[10*i])
            .normalized();
        }
        for (int i = 1; i < 10; i++) {
          vertices[i*11+10].normal = (normals[20*i-1] + normals[20*(i+1)-1] + normals[20*(i+1)-2])
            .normalized();
        }
        for (int i = 1; i < 10; i++) {
          vertices[110+i].normal = (normals[218+2*i] + normals[219+2*i] + normals[220+2*i])
            .normalized();
        }
        for (int i = 1; i < 10; i++)
          for (int j = 1; j < 10; j++) {
            vertices[i*11+j].normal = (normals[20*i+2*j] + normals[20*i+2*j-1]
              + normals[20*i+2*j-2] + normals[20*(i-1)+2*j-1] + normals[20*(i-1)+2*j]
              + normals[20*(i-1)+2*j+1]).normalized();
          }
        vertices[100].normal = (normals[209] + normals[210]).normalized();
        vertices[120].normal = normals[228].normalized();
      }

      s.attach(vertices, face_indicies, vertices.size());
    }

    Graphics::Renderer::init();
    Graphics::set_light(Graphics::DEFAULT_LIGHT, 0);

    s.init();

    while (!GAME_STATE.should_quit) {
      while (!s.end) {
        s.poll_events();
        s.update(&s);
        Graphics::Renderer::render(s.camera, s.VAO, s.meshes);

        std::stringstream sstream;
        sstream << "Engine Test (" << GAME_STATE.fps << " fps, frame #" << GAME_STATE.frame_count << ")";

        SDL_SetWindowTitle(GAME_STATE.window, sstream.str().c_str());
      }
    }
    s.destroy();
  }
  GameEngine::THE_GAME.quit();
  return 0;
}
