
#include <vsg/utils/StateComposer.h>

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
