#pragma once

/* <editor-fold desc="MIT License">

Copyright(c) 2018 Robert Osfield

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

</editor-fold> */

#include <vsg/io/Output.h>

#include <fstream>
#include <unordered_map>

namespace vsg
{

    class VSG_DECLSPEC BinaryOutput : public vsg::Output
    {
    public:
        BinaryOutput(std::ostream& output);

        // write property name if appropriate for format
        void writePropertyName(const char*) override {}

        template<typename T>
        void _write(size_t num, const T* value)
        {
            _output.write(reinterpret_cast<const char*>(value), num * sizeof(T));
        }

        // write contiguous array of value(s)
        void write(size_t num, const int8_t* value) override { _write(num, value); }
        void write(size_t num, const uint8_t* value) override { _write(num, value); }
        void write(size_t num, const int16_t* value) override { _write(num, value); }
        void write(size_t num, const uint16_t* value) override { _write(num, value); }
        void write(size_t num, const int32_t* value) override { _write(num, value); }
        void write(size_t num, const uint32_t* value) override { _write(num, value); }
        void write(size_t num, const int64_t* value) override { _write(num, value); }
        void write(size_t num, const uint64_t* value) override { _write(num, value); }
        void write(size_t num, const float* value) override { _write(num, value); }
        void write(size_t num, const double* value) override { _write(num, value); }

        void _write(const std::string& str)
        {
            uint32_t size = str.size();
            _output.write(reinterpret_cast<const char*>(&size), sizeof(uint32_t));
            _output.write(str.c_str(), size);
        }

        void write(size_t num, const std::string* value) override;

        // write object
        void write(const vsg::Object* object) override;

    protected:
        std::ostream& _output;

        using ObjectID = uint32_t;
#if 0
        using ObjectIDMap = std::map<const vsg::Object*, ObjectID>;
#else
        // 47% faster for overall write for large scene graph than std::map<>!
        using ObjectIDMap = std::unordered_map<const vsg::Object*, ObjectID>;
#endif

        ObjectIDMap _objectIDMap;
        ObjectID _objectID = 0;
    };

} // namespace vsg
