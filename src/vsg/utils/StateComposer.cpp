
#include <vsg/utils/StateComposer.h>
#include <vsg/io/Options.h>

#include <iostream>

using namespace vsg;

#if 0
    // notes on vsg::Builder, members and methods
    struct DescriptorKey
    {
        ref_ptr<Data> image;
        ref_ptr<Data> displacementMap;

        bool operator<(const DescriptorKey& rhs) const
        {
            VSG_COMPARE_PARAMETERS(image, rhs.image);
            return displacementMap < rhs.displacementMap;
        }
    };

    struct StateSettings
    {
        ref_ptr<DescriptorSetLayout> descriptorSetLayout;
        ref_ptr<PipelineLayout> pipelineLayout;
        ref_ptr<BindGraphicsPipeline> bindGraphicsPipeline;
        std::map<DescriptorKey, ref_ptr<BindDescriptorSets>> textureDescriptorSets;
    };

    std::map<StateInfo, StateSettings> _stateMap;

    ref_ptr<StateGroup> createStateGroup(const StateInfo& stateInfo = {});
    StateSettings& _getStateSettings(const StateInfo& stateInfo);
    ref_ptr<BindDescriptorSets> _createDescriptorSet(const StateInfo& stateInfo);

    // assign the BindDescriptorSets & BindGraphicsPipeline to a StateGroup
    void _assign(StateGroup& stateGroup, const StateInfo& stateInfo);

    // use image origin to decide what orientation to use for the texture coords
    vec3 y_texcoord(const StateInfo& info) const;
#endif

#if 0
    // notes on GraphicsPipelineStates that are to be used in configuration of vsg::GraphicsPiplines

    Provided by CompileTraversal/View:
        vsg::ViewportState
        vsg::MultisampleState
        vsg::DepthStencilState

    General behavior:
        vsg::DynamicState // VkPipelineDynamicStateCreateInfo vector of VkDynamicState

    Specific to geometries being rendered:
        vsg::VertexInputState // VkPipelineVertexInputStateCreateInfo - bindings (vector of VkVertexInputBindingDescription) and attributes (vector of VkVertexInputAttributeDescription)
        vsg::InputAssemblyState // VkPipelineInputAssemblyStateCreateInfo - topology (triangles, tri strips, lines, points etc.) and primitiveRestartEnable
        vsg::TessellationState // VkPipelineTessellationStateCreateInfo.patchControlPoints
        vsg::RasterizationState // VkPipelineRasterizationStateCreateInfo - face culling, polygon mode etc.
        vsg::ColorBlendState // VkPipelineColorBlendStateCreateInfo - blending ops and controls.
#endif

#if 0
    // notes on GraphicsPipline

    // VkGraphicsPipelineCreateInfo settings
    ShaderStages stages;
        vsg::ShaderStage: // VkPipelineShaderStageCreateInfo:
            VkPipelineShaderStageCreateFlags flags = 0;
            VkShaderStageFlagBits stage = {};
            ref_ptr<ShaderModule> module;
            std::string entryPointName;
            SpecializationConstants specializationConstants;

            vsg::ShaderModule: // VkShaderModuleCreateInfo
                std::string source;
                ref_ptr<ShaderCompileSettings> hints;

    // see above
    GraphicsPipelineStates pipelineStates;

    ref_ptr<PipelineLayout> layout; // VkPipelineLayoutCreateInfo
        VkPipelineLayoutCreateFlags flags = 0;
        PushConstantRanges pushConstantRanges;
        DescriptorSetLayouts setLayouts; // vector of vsg::DescriptorSetLayout
    Provided by CompileTraversal/View:
        ref_ptr<RenderPass> renderPass;
        uint32_t subpass;
#endif

#if 0
    // notes on DescriptorSetLayout, used by PipelineLayout and DescriptorSts

    vsg::DescriptorSetLayout -> VkDescriptorSetLayoutCreateInfo
    bindings -> std::vector<VkDescriptorSetLayoutBinding>;

    VkDescriptorSetLayoutBinding {
        uint32_t              binding;
        VkDescriptorType      descriptorType;
        uint32_t              descriptorCount;
        VkShaderStageFlags    stageFlags;
        const VkSampler*      pImmutableSamplers;
    }

    Descriptor
        uint32_t dstBinding; // naps to the VkDescriptorSetLayoutBinding.binding
        uint32_t dstArrayElement;
        VkDescriptorType descriptorType;

    DescriptorImage
        uint32_t descriptorCount
        vector<ImageInfo> imageInfos // maps to pImageInfo

    DescriptorBuffer
        uint32_t descriptorCount
        vector<ImageBuffer> bufferInfoList // maps to pImageInfo

    DescriptorTexelBufferView
        uint32_t descriptorCount
        vector<BufferView> texelBufferViews // maps to pTexelBufferView

    using Descriptors = std::vector<vsg::ref_ptr<vsg::Descriptor>>;

    // general thoughts:
    //     should Descriptor be renamed WriteDescriptorSet?
    //     should DescriptorImage be renamed DesciptorImages?
    //     should DescriptorBuffer be renamed DesciptorBuffers?
    //     should DescriptorTexBufferView be renamed DesciptorBufferViews?
#endif

#if 0
    // notes on DescriptorSet, BindDescriptorSets and BindDescriptorSet

    vsg::DescriptorSet
        // VkDescriptorSetAllocateInfo settings
        ref_ptr<DescriptorSetLayout> setLayout;
        Descriptors descriptors; // VkWriteDescriptorSet

        // VkWriteDescriptorSet provided by Desciptor
            wds.sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
            wds.dstBinding -> needs to map to VkDescriptorSetLayoutBinding.binding
            wds.dstArrayElement -> need to map within the VkDescriptorSetLayoutBinding.descriptorCount
            wds.descriptorCount -> wds.dstArrayElement + wds.descriptorCount need to map within the VkDescriptorSetLayoutBinding.descriptorCount
            wds.descriptorType -> VkDescriptorType
            wds.pImageInfo -> from vsg::DescriptorImage
            wds.pBufferInfo -> from vsg::DescriptorBuffer
            wds.pTexelBufferView -> from vsg::DescriptorBufferView


    vsg::BindDescriptorSets
        /// vkCmdBindDescriptorSets settings
        VkPipelineBindPoint pipelineBindPoint; // TODO not currently seralized
        ref_ptr<PipelineLayout> layout;
        uint32_t firstSet;
        DescriptorSets descriptorSets;

#endif
