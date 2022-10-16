#ifndef SHADER_H
#define SHADER_H

#include <string>

#include <glad/glad.h>
#include <glm/glm.hpp>

class Shader
{
public:
    Shader(const std::string &vsPath, const std::string &fsPath);
    void use();

    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;
    void setMatrix4f(const std::string &name, const glm::mat4 matrix) const;
    void setVector3f(const std::string &name, const glm::vec3 vector) const;
private:

    int createShader(GLenum type, const std::string &source, GLuint *shader);
    int createProgram(GLuint vs, GLuint fs);
    int openFile(const std::string &path, std::string &code);
    GLuint program;
};

#endif