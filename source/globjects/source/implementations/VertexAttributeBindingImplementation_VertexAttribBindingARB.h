#pragma once

#include <glbinding/gl/types.h>

#include <globjects-base/Singleton.h>

#include <globjects/globjects_api.h>

#include "AbstractVertexAttributeBindingImplementation.h"

namespace glo {

class VertexAttributeBindingImplementation_VertexAttribBindingARB : public AbstractVertexAttributeBindingImplementation
        , public Singleton<VertexAttributeBindingImplementation_VertexAttribBindingARB>
{
public:
    VertexAttributeBindingImplementation_VertexAttribBindingARB();
    virtual ~VertexAttributeBindingImplementation_VertexAttribBindingARB();

    virtual void bindAttribute(const VertexAttributeBinding * binding, gl::GLint attributeIndex) const override;
    virtual void bindBuffer(const VertexAttributeBinding * binding, const Buffer * vbo, gl::GLint baseoffset, gl::GLint stride) const override;

    virtual void setFormat(const VertexAttributeBinding * binding, gl::GLint size, gl::GLenum type, gl::GLboolean normalized, gl::GLuint relativeoffset) const override;
    virtual void setIFormat(const VertexAttributeBinding * binding, gl::GLint size, gl::GLenum type, gl::GLuint relativeoffset) const override;
    virtual void setLFormat(const VertexAttributeBinding * binding, gl::GLint size, gl::GLenum type, gl::GLuint relativeoffset) const override;
};

} // namespace glo