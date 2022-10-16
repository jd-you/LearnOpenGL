#include "shader.h"

#include <glm/gtc/type_ptr.hpp>

#include <fstream>
#include <iostream>
#include <sstream>


Shader::Shader(const std::string &vsPath, const std::string &fsPath)
{
    int ret;
    std::string code;
    GLuint vs;
    GLuint fs;
    ret = openFile(vsPath, code);
    if (ret != 0) {
        return;
    }
    ret = createShader(GL_VERTEX_SHADER, code, &vs);
    if (ret != 0) {
        return;
    }
    ret = openFile(fsPath, code);
    if (ret != 0) {
        return;
    }
    ret = createShader(GL_FRAGMENT_SHADER, code, &fs);
    if (ret != 0) {
        return;
    }

    ret = createProgram(vs, fs);

}


int Shader::createShader(GLenum type, const std::string &source, GLuint *shader)
{
    GLuint s = glCreateShader(type);
    GLchar const *codeChar = source.c_str();
    glShaderSource(s, 1, &codeChar, NULL);
    glCompileShader(s);

    GLint success;
    GLchar info[512];
    glGetShaderiv(s, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(s, sizeof(info), NULL, info);
        std::cout << "ERROR::SHADER::" << type << "::COMPILATION_FAILED\n" << info << std::endl;
        return -1;
    }
    *shader = s;
    return 0;
}

int Shader::openFile(const std::string &path, std::string &code)
{
    std::ifstream shaderFile;
    shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try {
        shaderFile.open(path);
        std::stringstream shaderStream;
        shaderStream << shaderFile.rdbuf();
        shaderFile.close();
        code = shaderStream.str();
    }
    catch (std::ifstream::failure e) {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ: ";
        std::cout << path << std::endl;
        return -1;
    }
    return 0;
}

int Shader::createProgram(GLuint vs, GLuint fs)
{
    GLint success;
    GLchar info[512];

    program = glCreateProgram();
    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if(!success)
    {
        glGetProgramInfoLog(program, 512, NULL, info);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << info << std::endl;
        glDeleteProgram(program);
        glDeleteShader(vs);
        glDeleteShader(fs);
        return -1;
    }
    glDeleteShader(vs);
    glDeleteShader(fs);
    return 0;
}
void Shader::setBool(const std::string &name, bool value) const
{
    glUniform1i(glGetUniformLocation(program, name.c_str()), value);
}
void Shader::setInt(const std::string &name, int value) const
{
    glUniform1i(glGetUniformLocation(program, name.c_str()), value);
}
void Shader::setFloat(const std::string &name, float value) const
{
    glUniform1f(glGetUniformLocation(program, name.c_str()), value);
}
void Shader::setMatrix4f(const std::string &name, const glm::mat4 matrix) const
{
    glUniformMatrix4fv(glGetUniformLocation(program, name.c_str()), 1, GL_FALSE, glm::value_ptr(matrix));
}
void Shader::setVector3f(const std::string &name, const glm::vec3 vector) const
{
    glUniform3fv(glGetUniformLocation(program, name.c_str()), 1, glm::value_ptr(vector));
}



void Shader::use()
{
    glUseProgram(program);
}