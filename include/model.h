#ifndef MODEL_H
#define MODEL_H

#include "shader.h"

#include <glm/glm.hpp>
#include <assimp/scene.h>

#include <string>
#include <vector>

typedef struct {
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 texCoord;
} Vertex;

typedef struct {
    unsigned int id;
    std::string type;
    aiString path;
} Texture;

class Mesh
{
public:
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    std::vector<Texture> textures;

    Mesh(const std::vector<Vertex> &vertices, const std::vector<unsigned int> &indices, const std::vector<Texture> &textures);
    void Draw(Shader shader);
private:
    unsigned int VAO, VBO, EBO;
    void setupMesh();
};

class Model
{
public:
    Model(char *path);
    void Draw(Shader shader);
    void moveX(float offset);
    void moveY(float offset);
private:
    std::vector<Mesh> meshes;
    std::string directory;
    std::vector<Texture> textures_loaded;

    void loadModel(std::string path);
    void processNode(aiNode *node, const aiScene *scene);
    Mesh processMesh(aiMesh *mesh, const aiScene *scene);
    std::vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName);
    unsigned int TextureFromFile(const char *path, const std::string &directory);

    glm::mat4 model;
};

#endif
