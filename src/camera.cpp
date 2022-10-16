#include "camera.h"

#include <glm/gtc/matrix_transform.hpp>


Camera::Camera(const Shader * shader, const ViewParam &viewParam, const ProjectParam &projectParam)
{
    pShader = shader;

    cameraPos = viewParam.pos;
    cameraTarget = viewParam.target;
    cameraFront = glm::normalize(cameraTarget - cameraPos);
    cameraUp = glm::normalize(viewParam.up);
    view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);

    fov = projectParam.fov;
    aspect = projectParam.aspect;
    zNear = projectParam.zNear;
    zFar = projectParam.zFar;
    projection = glm::perspective(fov, aspect, zNear, zFar);
    // pShader->setMatrix4f("projection", glm::mat4(1.0f));    // 每轮渲染都需要重新设置，在这里只设置一次没有用
} 

void Camera::update() const
{
    pShader->setMatrix4f("view", view);
    pShader->setMatrix4f("projection", projection);
}

void Camera::moveUp()
{
    // cameraPos.y += 1.0;
    // cameraFront = glm::normalize(cameraTarget - cameraPos);
    // view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
}
void Camera::moveDown()
{
    // cameraPos.y -= 1.0;
    // cameraFront = glm::normalize(cameraTarget - cameraPos);
    // view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
}