#ifndef CAMERA_H
#define CAMERA_H

#include "shader.h"

#include <glm/glm.hpp>

typedef struct {
    glm::vec3 pos;
    glm::vec3 target;
    glm::vec3 up;
} ViewParam;

typedef struct {
    float fov;
    float aspect;
    float zNear;
    float zFar;
} ProjectParam;

class Camera
{
public:
    Camera(const Shader * shader, const ViewParam &viewParam, const ProjectParam &projectParam);
    void update() const;

    void moveUp();
    void moveDown();

    glm::mat4 view;
    glm::mat4 projection;
private:
    glm::vec3 cameraPos;
    glm::vec3 cameraFront;
    glm::vec3 cameraUp;
    glm::vec3 cameraTarget;

    float fov;
    float aspect;
    float zNear;
    float zFar;

    const Shader *pShader;
};

#endif