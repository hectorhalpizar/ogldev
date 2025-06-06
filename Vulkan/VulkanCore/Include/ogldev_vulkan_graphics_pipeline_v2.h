/*
		Copyright 2024 Etay Meiri

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once
#include <vulkan/vulkan.h>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include "ogldev_types.h"
#include "ogldev_vulkan_core.h"
#include "Int/model_desc.h"

namespace OgldevVK {

class GraphicsPipelineV2 {

public:

	GraphicsPipelineV2(VkDevice Device,
					 GLFWwindow* pWindow,
					 VkRenderPass RenderPass,
					 VkShaderModule vs,
					 VkShaderModule fs,
					 int NumImages);

	~GraphicsPipelineV2();

	void Bind(VkCommandBuffer CmdBuf);

	void AllocateDescriptorSets(int NumSubmeshes, std::vector< std::vector<VkDescriptorSet> >& DescriptorSets);

	void UpdateDescriptorSets(const ModelDesc& ModelDesc,
							  std::vector<std::vector<VkDescriptorSet>>& DescriptorSets);

	VkPipelineLayout GetPipelineLayout() const { return m_pipelineLayout; }

private:

	void InitCommon(GLFWwindow* pWindow, VkRenderPass RenderPass, VkShaderModule vs, VkShaderModule fs);

	void AllocateDescriptorSetsInternal(int NumSubmeshes, std::vector< std::vector<VkDescriptorSet> >& DescriptorSets);
	void CreateDescriptorPool(int MaxSets);
	void CreateDescriptorSetLayout(bool IsVB, bool IsIB, bool IsTex, bool IsUniform);

	VkDevice m_device = VK_NULL_HANDLE;
	VkPipeline m_pipeline = VK_NULL_HANDLE;
	VkPipelineLayout m_pipelineLayout = VK_NULL_HANDLE;
	VkDescriptorPool m_descriptorPool = VK_NULL_HANDLE;
	VkDescriptorSetLayout m_descriptorSetLayout = VK_NULL_HANDLE;
	int m_numImages = 0;
};

}
