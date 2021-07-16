#ifndef SHADER_HPP
#define SHADER_HPP
#include <glad/glad.h> // Including glad to all req'd OpenGL Headers
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader 
{
public:
    // The Program ID
    unsigned int ID;
    // The shader will be read and built during construction
    Shader(const char* vertexPath, const char* fragmentPath);
    // Use/Activate the Shader
    void use();
    // Utility uniform funcs
    void setBool(const std::string& name, bool value) const;
    void setInt(const std::string& name, int value) const;
    void setFloat(const std::string& name, float value) const;
};

#endif
