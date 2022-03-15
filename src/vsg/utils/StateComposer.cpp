
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

    /// VkGraphicsPipelineCreateInfo settings
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

        GraphicsPipelineStates pipelineStates;
        ref_ptr<PipelineLayout> layout;
        ref_ptr<RenderPass> renderPass;
        uint32_t subpass;


#endif
