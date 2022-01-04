#ifndef SKITY_SRC_RENDER_HW_VK_PIPELINES_IMAGE_PIPELINE_HPP
#define SKITY_SRC_RENDER_HW_VK_PIPELINES_IMAGE_PIPELINE_HPP

#include "src/render/hw/vk/pipelines/static_pipeline.hpp"

namespace skity {

class StaticImagePipeline : public StaticPipeline {
 public:
  StaticImagePipeline(size_t push_const_size)
      : StaticPipeline(push_const_size) {}
  ~StaticImagePipeline() override = default;

  void UploadGradientInfo(GradientInfo const& info, GPUVkContext* ctx,
                          SKVkFrameBufferData* frame_buffer,
                          VKMemoryAllocator* allocator) override;

  void UploadImageTexture(VKTexture* texture, GPUVkContext* ctx,
                          SKVkFrameBufferData* frame_buffer,
                          VKMemoryAllocator* allocator) override;

 protected:
  VkDescriptorSetLayout GenerateColorSetLayout(GPUVkContext* ctx) override;

 private:
  glm::vec4 bounds_info_ = {};
};

class StencilDiscardImagePipeline : public StaticImagePipeline {
 public:
  StencilDiscardImagePipeline(size_t push_const_size)
      : StaticImagePipeline(push_const_size) {}
  ~StencilDiscardImagePipeline() override = default;

 protected:
  VkPipelineDepthStencilStateCreateInfo GetDepthStencilStateCreateInfo()
      override;
};

class StencilClipImagePipeline : public StaticImagePipeline {
 public:
  StencilClipImagePipeline(size_t push_const_size)
      : StaticImagePipeline(push_const_size) {}
  ~StencilClipImagePipeline() override = default;

 protected:
  VkPipelineDepthStencilStateCreateInfo GetDepthStencilStateCreateInfo()
      override;
};

class StencilKeepImagePipeline : public StaticImagePipeline {
 public:
  StencilKeepImagePipeline(size_t push_const_size)
      : StaticImagePipeline(push_const_size) {}
  ~StencilKeepImagePipeline() override = default;

 protected:
  VkPipelineDepthStencilStateCreateInfo GetDepthStencilStateCreateInfo()
      override;
};

}  // namespace skity

#endif  // SKITY_SRC_RENDER_HW_VK_PIPELINES_IMAGE_PIPELINE_HPP