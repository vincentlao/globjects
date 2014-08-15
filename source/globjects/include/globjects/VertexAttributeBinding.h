#pragma once

#include <glbinding/gl/types.h>
#include <glbinding/gl/enum.h>
#include <glbinding/gl/boolean.h>

#include <globjects-base/Referenced.h>

#include <globjects/globjects_api.h>

namespace glo 
{

class Buffer;
class VertexArrayObject;
class VertexAttributeBindingImplementation;

class GLOBJECTS_API VertexAttributeBinding : public Referenced
{
	friend class VertexAttributeBindingImplementation;

public:
	VertexAttributeBinding(
        VertexArrayObject * vao
    ,   const gl::GLint bindingIndex);

    const VertexArrayObject * vao() const;
    VertexArrayObject * vao();

	void setAttribute(gl::GLint attributeIndex);
	void setBuffer(
        const Buffer * vbo
    ,   gl::GLint baseoffset
    ,   gl::GLint stride);

	void setFormat(
        gl::GLint size
    ,   gl::GLenum type
    ,   gl::GLboolean normalized = gl::GL_FALSE
    ,   gl::GLuint relativeoffset = 0);
	void setIFormat(
        gl::GLint size
    ,   gl::GLenum type
    ,   gl::GLuint relativeoffset = 0);
	void setLFormat(
        gl::GLint size
    ,   gl::GLenum type
    ,   gl::GLuint relativeoffset = 0);

    gl::GLint attributeIndex() const;
    gl::GLint bindingIndex() const;
    const Buffer * buffer() const;

protected:
    ~VertexAttributeBinding();

    VertexArrayObject * m_vao; // TODO: weak_ptr?
   
    gl::GLint m_bindingIndex;
    gl::GLint m_attributeIndex;
    
    const Buffer * m_vbo;

    VertexAttributeBindingImplementation * m_implementation;
};

} // namespace glo