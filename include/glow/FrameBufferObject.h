#pragma once

#include "declspec.h"

#include <glow/Object.h>
#include <glow/Texture.h>
#include <glow/RenderBufferObject.h>

#include <string>
#include <unordered_map>

// http://www.opengl.org/wiki/Framebuffer_Object

namespace glow {

class GLOW_API ColorAttachment : public Referenced
{
public:
	ColorAttachment(GLenum attachment);

	GLenum attachment() const;
protected:
	GLenum _attachment;
};

class GLOW_API TextureAttachment : public ColorAttachment
{
public:
	TextureAttachment(Texture* texture, GLenum attachment);
protected:
	ref_ptr<Texture> _texture;
};

class GLOW_API RenderBufferAttachment : public ColorAttachment
{
public:
	RenderBufferAttachment(RenderBufferObject* renderBuffer, GLenum attachment);
protected:
	ref_ptr<RenderBufferObject> _renderBuffer;
};


class GLOW_API FrameBufferObject : public Object
{
public:
	FrameBufferObject();
	~FrameBufferObject();

	void bind(GLenum target = GL_FRAMEBUFFER);
	void unbind();

	void setParameter(GLenum pname, GLint param);

	void attachTexture(GLenum attachment, Texture* texture, GLint level = 0);
	void attachTexture1D(GLenum attachment, Texture* texture, GLint level = 0);
	void attachTexture2D(GLenum attachment, Texture* texture, GLint level = 0);
	void attachTextureLayer(GLenum attachment, Texture* texture, GLint level = 0, GLint layer = 0);
	void attachRenderBuffer(GLenum attachment, RenderBufferObject* renderBuffer);

	void blit(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint destX0, GLint destY0, GLint destX1, GLint destY1, GLbitfield mask, GLenum filter);

	GLenum checkStatus();
	std::string statusString();
	std::string statusString(GLenum status);
	void printStatus(bool onlyErrors = false);
protected:
	GLenum _target;
	std::unordered_map<GLenum, ref_ptr<ColorAttachment>> _attachments;

	void attach(ColorAttachment* attachment);

	static GLuint genFrameBuffer();
};

} // namespace glow
